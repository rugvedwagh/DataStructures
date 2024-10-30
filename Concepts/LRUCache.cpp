class Node {
public:
    int key, value;
    Node* prev;
    Node* next;

    Node(int key, int value) {
        this->key = key;
        this->value = value;

        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
private:
    Node* head;
    Node* tail;
    int cap;
    map<int, Node*> mp;

    void addnode(Node* cur) {
        Node* temp = head->next;
        cur->next = temp;
        cur->prev = head;
        head->next = cur;
        temp->prev = cur;
    }

    void delnode(Node* cur) {
        Node* prevv = cur->prev;
        Node* nextt = cur->next;
        prevv->next = nextt;
        nextt->prev = prevv;
    }

public:
    LRUCache(int capacity) {
        this->cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            Node* cur = mp[key];
            int res = cur->value;
            delnode(cur);
            addnode(cur);

            mp[key] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* cur = mp[key];
            mp.erase(key);
            delnode(cur);
        }
        if (mp.size() == cap) {
            mp.erase(tail->prev->key);
            delnode(tail->prev);
        }

        addnode(new Node(key, value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
