#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

class CircularDoublyLinkedList {
    Node* head;

public:
    CircularDoublyLinkedList() {
        head = NULL;
    }

    void insertEnd(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
            return;
        }

        Node* last = head->prev;

        newNode->next = head;
        newNode->prev = last;

        last->next = newNode;
        head->prev = newNode;
    }

    void insertBeginning(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
            return;
        }

        Node* last = head->prev;

        newNode->next = head;
        newNode->prev = last;

        last->next = newNode;
        head->prev = newNode;

        head = newNode;
    }

    void insertAtPosition(int value, int position) {
        if (position == 1) {
            insertBeginning(value);
            return;
        }

        if (head == NULL)
            return;

        Node* current = head;

        for (int i = 1; i < position - 1; i++) {
            current = current->next;

            if (current == head) {
                cout << "Invalid position" << endl;
                return;
            }
        }

        Node* newNode = new Node(value);

        newNode->next = current->next;
        newNode->prev = current;

        current->next->prev = newNode;
        current->next = newNode;
    }

    void deleteNode(int value) {
        if (head == NULL)
            return;

        Node* current = head;

        do {
            if (current->data == value)
                break;

            current = current->next;

        } while (current != head);

        if (current->data != value)
            return;

        if (current->next == current) {
            delete current;
            head = NULL;
            return;
        }

        current->prev->next = current->next;
        current->next->prev = current->prev;

        if (current == head)
            head = current->next;

        delete current;
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;

        do {
            cout << temp->data << " <-> ";
            temp = temp->next;
        } while (temp != head);

        cout << "HEAD" << endl;
    }
};

int main() {
    CircularDoublyLinkedList list;

    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);

    list.display();

    list.insertBeginning(5);
    list.display();

    list.insertAtPosition(15, 3);
    list.display();

    list.deleteNode(20);
    list.display();

    return 0;
}
