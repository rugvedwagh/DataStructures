#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value){
        this->data = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BST
{
private:
    Node *root;

public:
    BST(){
        root = nullptr;
    }

    Node *getroot()
    {
        return root;
    }

    void insert(int value)
    {
        root = insertRecursive(root, value);
    }

    void del(int key)
    {
        root = deleteNode(root, key);
    }

    bool search(int key)
    {
        return searchRecursive(root, key);
    }

    void inorderTraversal()
    {
        inorderRecursive(root);
    }

    void displayLevel()
    {
        levelOrderTraversal(root);
    }

    int height()
    {
        return findHeight(root);
    }

    void mirrorImage()
    {
        root = createMirrorImage(root);
    }

private:
    Node *insertRecursive(Node *current, int value)
    {
        if (!current)
        {
            current = new Node(value);
        }
        else if (value < current->data)
        {
            current->left = insertRecursive(current->left, value);
        }
        else if (value > current->data)
        {
            current->right = insertRecursive(current->right, value);
        }
        return current;
    }

    Node *deleteNode(Node *current, int key)
    {
        if (!current)
            return current;

        if (key < current->data)
            current->left = deleteNode(current->left, key);
        else if (key > current->data)
            current->right = deleteNode(current->right, key);
        else
        {
            if (!current->left)
            {
                Node *temp = current->right;
                delete current;
                return temp;
            }
            else if (!current->right)
            {
                Node *temp = current->left;
                delete current;
                return temp;
            }

            Node *temp = findMinNode(current->right);
            current->data = temp->data;
            current->right = deleteNode(current->right, temp->data);
        }
        return current;
    }

    bool searchRecursive(Node *current, int key)
    {
        if (!current)
            return false;

        if (current->data == key)
            return true;

        if (key < current->data)
            return searchRecursive(current->left, key);

        return searchRecursive(current->right, key);
    }

    void inorderRecursive(Node *current)
    {
        if (current)
        {
            inorderRecursive(current->left);
            cout << current->data << " ";
            inorderRecursive(current->right);
        }
    }

    void levelOrderTraversal(Node *root)
    {
        if (!root)
            return;

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *current = q.front();
            q.pop();

            cout << current->data << " ";

            if (current->left)
                q.push(current->left);

            if (current->right)
                q.push(current->right);
        }
    }

    int findHeight(Node *current)
    {
        if (!current)
            return -1;

        int leftHeight = findHeight(current->left);
        int rightHeight = findHeight(current->right);

        return max(leftHeight, rightHeight) + 1;
    }

    Node *createMirrorImage(Node *current)
    {
        if (!current)
            return nullptr;

        Node *temp = current->left;
        current->left = createMirrorImage(current->right);
        current->right = createMirrorImage(temp);

        return current;
    }

    Node *findMinNode(Node *current)
    {
        while (current->left)
            current = current->left;
        return current;
    }
};

int main()
{
    BST tree;

    // Insert nodes
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    // Inorder traversal
    cout << "In-order traversal: ";
    tree.inorderTraversal();
    cout << endl;

    // Search for a node
    if (tree.search(60))
        cout << "Found 60 in the tree." << endl;
    else
        cout << "60 not found in the tree." << endl;

    // Delete a node
    tree.del(70);

    // Display the tree level-wise
    cout << "Level-order traversal: ";
    tree.displayLevel();
    cout << endl;

    // Get the height of the tree
    cout << "Height of the tree: " << tree.height() << endl;

    // Create a mirror image of the tree
    tree.mirrorImage();

    // Inorder traversal after creating a mirror image
    cout << "In-order traversal of mirror image: ";
    tree.inorderTraversal();
    cout << endl;

    return 0;
}
