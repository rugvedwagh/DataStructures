#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void append(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void displayForward() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void displayBackward() {
        Node* current = tail;
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    void deleteNode(int value) {
        Node* current = head;
        while (current && current->data != value) {
            current = current->next;
        }

        if (!current) {
            cout << "Value not found in the list." << endl;
            return;
        }

        if (current->prev) {
            current->prev->next = current->next;
        } else {
            head = current->next;
        }

        if (current->next) {
            current->next->prev = current->prev;
        } else {
            tail = current->prev;
        }

        delete current;
    }

    void reverse() {
        Node* current = head;
        Node* temp = nullptr;

        while (current) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp) {
            head = temp->prev;
        }
    }
};

int main() {
    DoublyLinkedList dll;

    dll.append(5);
    dll.append(10);
    dll.append(15);
    dll.append(20);

    cout << "Forward: ";
    dll.displayForward();

    cout << "Backward: ";
    dll.displayBackward();

    dll.reverse();

    cout << "After reversing:" << endl;
    cout << "Forward: ";
    dll.displayForward();
    dll.deleteNode(5);

    cout << "Backward: ";
    dll.displayBackward();

    return 0;
}
