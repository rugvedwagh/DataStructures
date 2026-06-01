class Node {
public:
    Node *next, *prev;
    int key, val, freq;

    Node(int key, int val) {
        this->key = key;
        this->val = val;

        this->next = NULL;
        this->prev = NULL;
        this->freq = 1;
    }
};

class DLL {
private:
    Node *head, *tail;
    int size;

public:
    DLL() {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void add(Node* cur) {
        cur->prev = head;
        cur->next = head->next;
        head->next->prev = cur;
        head->next = cur;
        size++;
    }

    void deleteNode(Node* cur) {
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        size--;
    }

    Node* removeLast() {
        if (size == 0) {
            return NULL;
        }

        Node* lru = tail->prev;
        deleteNode(lru);
        return lru;
    }

    int getSize() { return this->size; }
};

class LFUCache {
private:
    int capacity;
    int minFreq;

    map<int, Node*> mp; // key -> Node
    map<int, DLL*> freqToList;

    void updateFreq(Node* node) {
        int oldFreq = node->freq;
        DLL* oldList = freqToList[oldFreq];

        oldList->deleteNode(node);

        if (oldFreq == minFreq && oldList->getSize() == 0)
            minFreq++;

        node->freq++;

        if (freqToList.find(node->freq) == freqToList.end())
            freqToList[node->freq] = new DLL();

        freqToList[node->freq]->add(node);
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (capacity == 0 or mp.find(key) == mp.end()) {
            return -1;
        }

        Node* curr = mp[key];
        updateFreq(curr);

        return curr->val;
    }

    void put(int key, int value) {
        if (capacity == 0) {
            return;
        }

        if (mp.find(key) != mp.end()) {
            Node* curr = mp[key];
            curr->val = value;
            updateFreq(curr);
        } else {
            if (mp.size() == capacity) {
                DLL* list = freqToList[minFreq];
                Node* nodeToRemove = list->removeLast();
                mp.erase(nodeToRemove->key);
                delete nodeToRemove;
            }

            Node* curr = new Node(key, value);
            mp[key] = curr;

            if (freqToList.find(1) == freqToList.end()) {
                freqToList[1] = new DLL();
            }

            freqToList[1]->add(curr);
            minFreq = 1;
        }
    }
};
