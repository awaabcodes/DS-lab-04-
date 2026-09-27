#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class CircularLinkedList {
    Node* head;

public:
    CircularLinkedList() {
        head = NULL;
    }

    void insertEnd(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;

        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }

    void insertBeginning(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;

        while (temp->next != head)
            temp = temp->next;

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    void insertAtPosition(int value, int position) {
        if (position == 1) {
            insertBeginning(value);
            return;
        }

        if (head == NULL)
            return;

        Node* temp = head;

        for (int i = 1; i < position - 1; i++) {
            temp = temp->next;

            if (temp == head) {
                cout << "Invalid position" << endl;
                return;
            }
        }

        Node* newNode = new Node(value);

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteNode(int value) {
        if (head == NULL)
            return;

        if (head->data == value && head->next == head) {
            delete head;
            head = NULL;
            return;
        }

        if (head->data == value) {
            Node* last = head;

            while (last->next != head)
                last = last->next;

            Node* temp = head;

            head = head->next;
            last->next = head;

            delete temp;
            return;
        }

        Node* prev = head;
        Node* current = head->next;

        while (current != head) {
            if (current->data == value) {
                prev->next = current->next;
                delete current;
                return;
            }

            prev = current;
            current = current->next;
        }
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;

        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);

        cout << "HEAD" << endl;
    }
};

int main() {
    CircularLinkedList list;

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
