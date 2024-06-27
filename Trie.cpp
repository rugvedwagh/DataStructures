class Node {
private:
    Node* links[26];
    bool flag;

public:
    Node() {
        this->flag = false;
        for (int i = 0; i < 26; i++) {
            links[i] = NULL;
        }
    }

    Node* get(char c) { return links[c-'a']; }

    void put(char c, Node* temp) { links[c - 'a'] = temp; }

    bool containsKey(char c) { return links[c - 'a'] != NULL; }

    void setEnd() { flag = true; }

    bool isEnd() { return flag; }
};

class Trie {
private:
    Node* root;

public:
    Trie() { root = new Node(); }

    void insert(string word) {
        Node* temp = root;
        for (char c : word) {
            if (!temp->containsKey(c)) {
                temp->put(c, new Node());
            }
            temp = temp->get(c);
        }
        temp->setEnd();
    }

    bool search(string word) {
        Node* temp = root;
        for (char c : word) {
            if (!temp->containsKey(c)) {
                return false;
            }
            temp = temp->get(c);
        }

        return temp->isEnd();
    }

    bool startsWith(string prefix) {
        Node* temp = root;

        for (char c : prefix) {
            if (!temp->containsKey(c)) {
                return false;
            }
            temp = temp->get(c);
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
