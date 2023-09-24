#include <iostream>
using namespace std;

class node {
  public:
      int val;
      node* next;
      
      node(int value){
          this->val = value;
          this->next = nullptr;
      }
};

class MyLinkedList {
  private:
      node* head;
      int length;
      
  public:
      MyLinkedList(){
          this->head = nullptr;
          this->length = 0;
      }
  
      int get(int index) {
          if (index < 0 || index >= length) {
              return -1;
          }
          
          node* current = head;
          for (int i = 0; i < index; ++i) {
              current = current->next;
          }
          
          return current->val;
      }
  
      void addAtHead(int val) {
          node* new_node = new node(val);
          new_node->next = head;
          head = new_node;
          length++;
      }
  
      void addAtTail(int val) {
          node* new_node = new node(val);
          if (!head) {
              head = new_node;
          } else {
              node* current = head;
              while (current->next) {
                  current = current->next;
              }
              current->next = new_node;
          }
          length++;
      }
  
      void addAtIndex(int index, int val) {
          if (index < 0 || index > length) {
              return;
          }
  
          if (index == 0) {
              addAtHead(val);
          } else {
              node* new_node = new node(val);
              node* current = head;
              for (int i = 0; i < index - 1; ++i) {
                  current = current->next;
              }
              new_node->next = current->next;
              current->next = new_node;
              length++;
          }
      }
  
      void deleteAtHead() {
          if (!head) {
              return;
          }
  
          node* temp = head;
          head = head->next;
          delete temp;
          length--;
      }
  
      void deleteAtIndex(int index) {
          if (index < 0 || index >= length) {
              return;
          }
  
          if (index == 0) {
              deleteAtHead();
          } else {
              node* current = head;
              for (int i = 0; i < index - 1; ++i) {
                  current = current->next;
              }
              node* temp = current->next;
              current->next = current->next->next;
              delete temp;
              length--;
          }
      }
  
      void reverse() {
          node* prev = nullptr;
          node* current = head;
          node* next_node = nullptr;
  
          while (current != nullptr) {
              next_node = current->next;
              current->next = prev;
              prev = current;
              current = next_node;
          }
  
          head = prev;
      }
      
      void printList() {
        node* current = head;
        while (current) {
            cout << current->val << " -> ";
            current = current->next;
        }
        cout << "nullptr" << std::endl;
      }
};

int main(){
  MyLinkedList m;
  m.addAtHead(4);
  m.addAtHead(1);
  m.addAtHead(7);
  m.addAtTail(99);
  m.addAtIndex(3,0);
  m.printList();
  m.reverse();
  m.deleteAtIndex(2);
  m.deleteAtHead();
  m.printList();
}
