


#include "test.hpp"


class Node {
private:
    // int data;
    // Node* next;

public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {
        cout << "constructor - Node" << endl;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {
        cout << "constructor - LinedList" << endl;
    }

    void insertAtBeginning(int newData) {
        Node* newNode = new Node(newData);
        newNode->next = head;
        head = newNode;
    }

    void printLinedList() {
        Node* current = head;
        while(current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main(void) {
    vector<int> arr = {10, 1, 7, 2, 3, 4, 5, 9, 6, 8, 0};

    LinkedList myList;
    myList.insertAtBeginning(10);
    // myList.

    return 0;
}