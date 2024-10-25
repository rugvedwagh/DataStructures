class TrieNode
{
public:
    TrieNode *children[26]; // Assuming lowercase English alphabet
    bool isEndOfWord;
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
        isEndOfWord = false;
    }
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *current = root;
        for (char ch : word)
        {
            int index = ch - 'a';
            if (!current->children[index])
            {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->isEndOfWord = true;
    }

    bool search(TrieNode *root, string word)
    {
        TrieNode *current = root;
        for (char ch : word)
        {
            int index = ch - 'a';
            if (!current->children[index])
            {
                return false;
            }
            current = current->children[index];
        }
        return current->isEndOfWord;
    }

    void findAllWordsWithPrefix(TrieNode *root, string prefix, vector<string> &result)
    {
        TrieNode *current = root;
        for (char ch : prefix)
        {
            int index = ch - 'a';
            if (!current->children[index])
            {
                return; // Prefix not found
            }
            current = current->children[index];
        }
        // Perform a depth-first search to collect words under this node.
        findAllWordsFromNode(current, prefix, result);
    }

    void findAllWordsFromNode(TrieNode *node, string currentWord, vector<string> &result)
    {
        if (node->isEndOfWord)
        {
            result.push_back(currentWord);
        }
        for (int i = 0; i < 26; i++)
        {
            if (node->children[i])
            {
                char ch = 'a' + i;
                findAllWordsFromNode(node->children[i], currentWord + ch, result);
            }
        }
    }

    bool deleteWord(TrieNode *root, string word, int index)
    {
        if (index == word.length())
        {
            if (!root->isEndOfWord)
                return false; // Word doesn't exist
            root->isEndOfWord = false;
            return isEmptyNode(root);
        }
        int chIndex = word[index] - 'a';
        if (!root->children[chIndex])
            return false; // Word doesn't exist
        bool canDelete = deleteWord(root->children[chIndex], word, index + 1);
        if (canDelete)
        {
            delete root->children[chIndex];
            root->children[chIndex] = nullptr;
            return isEmptyNode(root);
        }
        return false;
    }

    bool isEmptyNode(TrieNode *node)
    {
        for (int i = 0; i < 26; i++)
        {
            if (node->children[i])
                return false;
        }
        return true;
    }
};
