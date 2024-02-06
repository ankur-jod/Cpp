#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    // Function to insert a node at the beginning of the list
    void insertAtBegin(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        if (head == nullptr) {
            newNode->next = newNode;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
        cout << "Node inserted at the beginning successfully." << endl;
    }

    // Function to insert a node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        if (head == nullptr) {
            newNode->next = newNode;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
        cout << "Node inserted at the end successfully." << endl;
    }

    // Function to insert a node at a specific position in the list
    void insertAtPosition(int value, int position) {
        if (position <= 0) {
            cout << "Invalid position. Please enter a positive position." << endl;
            return;
        }
        if (position == 1) {
            insertAtBegin(value);
            return;
        }
        Node* newNode = new Node;
        newNode->data = value;
        Node* temp = head;
        int count = 1;
        while (count < position - 1 && temp->next != head) {
            temp = temp->next;
            count++;
        }
        if (count < position - 1) {
            cout << "Invalid position. The list is not long enough." << endl;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Node inserted at position " << position << " successfully." << endl;
    }

    // Function to delete a node from the beginning of the list
    void deleteFromBegin() {
        if (head == nullptr) {
            cout << "The list is empty. No node to delete." << endl;
            return;
        }
        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = head->next;
            delete head;
            head = temp->next;
        }
        cout << "Node deleted from the beginning successfully." << endl;
    }

    // Function to delete a node from the end of the list
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "The list is empty. No node to delete." << endl;
            return;
        }
        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            Node* prev = nullptr;
            while (temp->next != head) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = head;
            delete temp;
        }
        cout << "Node deleted from the end successfully." << endl;
    }

    // Function to delete a node from a specific position in the list
    void deleteFromPosition(int position) {
        if (head == nullptr) {
            cout << "The list is empty. No node to delete." << endl;
            return;
        }
        if (position <= 0) {
            cout << "Invalid position. Please enter a positive position." << endl;
            return;
        }
        if (position == 1) {
            deleteFromBegin();
            return;
        }
        Node* temp = head;
        Node* prev = nullptr;
        int count = 1;
        while (count < position && temp->next != head) {
            prev = temp;
            temp = temp->next;
            count++;
        }
        if (count < position) {
            cout << "Invalid position. The list is not long enough." << endl;
            return;
        }
        prev->next = temp->next;
        delete temp;
        cout << "Node deleted from position " << position << " successfully." << endl;
    }

    // Function to display the circular linked list
    void display() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }
        Node* temp = head;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList list;
    int choice, value, position;

    do {
        cout << "----- Menu -----" << endl;
        cout << "1. Insert at beginning" << endl;
        cout << "2. Insert at end" << endl;
        cout << "3. Insert at a specific position" << endl;
        cout << "4. Delete from beginning" << endl;
        cout << "5. Delete from end" << endl;
        cout << "6. Delete from a specific position" << endl;
        cout << "7. Display" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                list.insertAtBegin(value);
                break;
            case 2:
                cout << "Enter the value to insert: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter the value to insert: ";
                cin >> value;
                cout << "Enter the position: ";
                cin >> position;
                list.insertAtPosition(value, position);
                break;
            case 4:
                list.deleteFromBegin();
                break;
            case 5:
                list.deleteFromEnd();
                break;
            case 6:
                cout << "Enter the position: ";
                cin >> position;
                list.deleteFromPosition(position);
                break;
            case 7:
                list.display();
                break;
            case 8:
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
        cout << endl;
    } while (choice != 8);

    return 0;
}