
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
class Node {
public:
    Node* child[26];
    bool end;

    Node() {
        this->end = false;
        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() { 
        root = new Node(); 
    }

    void insert(string word) {
        Node* temp = root;

        for (auto i : word) {
            if (temp->child[i - 'a'] == NULL) {
                temp->child[i - 'a'] = new Node();
            }
            temp = temp->child[i - 'a'];
        }
        temp->end = true;
    }

    bool search(string word) {
        Node* temp = root;

        for (auto i : word) {
            if (temp->child[i - 'a'] == NULL) {
                return false;
            }
            temp = temp->child[i - 'a'];
        }

        return temp->end;
    }

    bool startsWith(string prefix) {
        Node* temp = root;
        for (auto i : prefix) {
            if (temp->child[i - 'a'] == NULL) {
                return false;
            }
            temp = temp->child[i - 'a'];
        }

        return true;
    }
};
