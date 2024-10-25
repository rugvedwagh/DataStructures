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

    bool deleteHelper(Node* node, const string& word, int depth) {
        if (!node) return false;

        if (depth == word.size()) {
            if (!node->end) return false;

            node->end = false;

            for (int i = 0; i < 26; i++) {
                if (node->child[i]) return false;
            }

            return true;
        }

        int index = word[depth] - 'a';
        if (deleteHelper(node->child[index], word, depth + 1)) {
            delete node->child[index];
            node->child[index] = NULL;

            return !node->end && all_of(begin(node->child), end(node->child), [](Node* n) { return n == NULL; });
        }

        return false;
    }

    void deleteWord(const string& word) {
        deleteHelper(root, word, 0);
    }
};
