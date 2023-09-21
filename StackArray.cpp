#include <iostream>
using namespace std;
const int MAX_SIZE = 100;

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack is full. Cannot push." << endl;
            return;
        }
        arr[++top] = value;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        top--;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot peek." << endl;
            return -1;
        }
        return arr[top];
    }

    void reverse() {
        if (isEmpty()) {
            return; // Base case: stack is empty
        }

        int item = peek();
        pop();
        reverse(); // Recursively reverse the remaining stack

        insertAtBottom(item); // Insert the item at the bottom of the reversed stack
    }

    void insertAtBottom(int item) {
        if (isEmpty()) {
            push(item); // When the stack is empty, push the item
            return;
        }

        int temp = peek();
        pop();

        insertAtBottom(item); // Recursively insert the item at the bottom

        push(temp); // Push the temporary item back onto the stack
    }
};

int main() {
    Stack myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    cout << "Stack before reverse: ";
    while (!myStack.isEmpty()) {
        cout << myStack.peek() << " ";
        myStack.pop();
    }
    cout << endl;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    myStack.reverse();

    cout << "Stack after reverse: ";
    while (!myStack.isEmpty()) {
        cout << myStack.peek() << " ";
        myStack.pop();
    }
    cout << endl;

    return 0;
}
