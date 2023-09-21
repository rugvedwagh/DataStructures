#include <iostream>

using namespace std;

class node
{
public:
    int val;
    node *next;

    node(int val)
    {
        this->val = val;
        this->next = nullptr;
    }
};

class linkedlist
{
private:
    node *head;

public:
    linkedlist()
    {
        head = nullptr;
    }

    void insert(int val)
    {
        node *cur = new node(val);
        cur->next = head;
        head = cur;
    }

    void display()
    {
        node *temp = head;
        while (temp)
        {
            cout << " " << temp->val;
            temp = temp->next;
        }
        cout << " nullptr" << endl;
    }

    // Function to delete a node with a specific value
    void deleteNode(int val)
    {
        node *current = head;
        node *prev = nullptr;

        while (current and current->val != val)
        {
            prev = current;
            current = current->next;
        }

        if (!current)
        {
            // Value not found
            return;
        }

        if (!prev)
        {
            // If the node to be deleted is the head
            head = current->next;
        }
        else
        {
            // If the node to be deleted is not the head
            prev->next = current->next;
        }

        delete current;
    }

    // Function to reverse the linked list
    void reverse()
    {
        node *prev = nullptr;
        node *current = head;
        node *next = nullptr;

        while (current)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev; // Update the head to the new first node (formerly the last node)
    }

    // Floyd's algorithm
    bool hasLoop()
    {
        if (!head)
        {
            return false; // No loop in an empty list
        }

        node *slow = head;
        node *fast = head;

        while (fast and fast->next)
        {
            slow = slow->next;       // Move one step
            fast = fast->next->next; // Move two steps

            if (slow == fast)
            {
                // If the slow and fast pointers meet, there's a loop
                return true;
            }
        }

        return false; // If we reach the end of the list, there's no loop
    }
};

int main()
{
    linkedlist obj;
    obj.insert(3);
    obj.insert(1);
    obj.insert(12);
    obj.insert(6);

    cout << "Linked List: ";
    obj.display();

    // Delete a node with value 1
    obj.deleteNode(1);

    cout << "Linked List after deleting 1: ";
    obj.display();

    // Reverse the linked list
    obj.reverse();

    cout << "Linked List after reversing: ";
    obj.display();
    cout<<obj.hasLoop();

    return 0;
}
