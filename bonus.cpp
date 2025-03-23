// 1.

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
Node * createNode(int n){
    Node* newnode=new Node;
    newnode->data=n;
    newnode->next=NULL;
    return newnode;
}

void destroy(Node* &head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head =NULL; 
}

//2.1
#include <iostream>

struct Node {
    int data;
    Node* next;
};

class SortedSinglyLinkedList {
public:
    Node* head;

    SortedSinglyLinkedList() : head(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node{value, nullptr};
        if (!head || head->data >= value) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next && current->next->data < value) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }

    ~SortedSinglyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    SortedSinglyLinkedList list;
    list.insert(5);
    list.insert(2);
    list.insert(8);
    list.insert(3);
    list.display(); // Output: 2 -> 3 -> 5 -> 8 -> NULL
    return 0;
}



//2.2
#include <iostream>

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

class SortedDoublyLinkedList {
public:
    DNode* head;

    SortedDoublyLinkedList() : head(nullptr) {}

    void insert(int value) {
        DNode* newNode = new DNode{value, nullptr, nullptr};
        if (!head || head->data >= value) {
            newNode->next = head;
            if (head) head->prev = newNode;
            head = newNode;
            return;
        }

        DNode* current = head;
        while (current->next && current->next->data < value) {
            current = current->next;
        }

        newNode->next = current->next;
        if (current->next) current->next->prev = newNode;
        newNode->prev = current;
        current->next = newNode;
    }

    void display() {
        DNode* temp = head;
        while (temp) {
            std::cout << temp->data << " <-> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }

    ~SortedDoublyLinkedList() {
        while (head) {
            DNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    SortedDoublyLinkedList list;
    list.insert(5);
    list.insert(2);
    list.insert(8);
    list.insert(3);
    list.display(); // Output: 2 <-> 3 <-> 5 <-> 8 <-> NULL
    return 0;
}