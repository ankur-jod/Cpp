#include <iostream>

using namespace std;

// Node structure for doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Class for doubly linked list
class DoublyLinkedList {
private:
    Node* head;

public:
    // Constructor
    DoublyLinkedList() {
        head = nullptr;
    }

    // Function to insert a node at the beginning of the list
    void insertAtBegin(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = head;

        if (head != nullptr) {
            head->prev = newNode;
        }

        head = newNode;
        cout << "Node inserted at the beginning successfully." << endl;
    }

    // Function to insert a node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            newNode->prev = nullptr;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }

        cout << "Node inserted at the end successfully." << endl;
    }

    // Function to insert a node at a specific position in the list
    void insertAtPosition(int value, int position) {
        if (position <= 0) {
            cout << "Invalid position. Node cannot be inserted." << endl;
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
        while (temp != nullptr && count < position - 1) {
            temp = temp->next;
            count++;
        }

        if (temp == nullptr) {
            cout << "Invalid position. Node cannot be inserted." << endl;
            return;
        }

        newNode->prev = temp;
        newNode->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;

        cout << "Node inserted at position " << position << " successfully." << endl;
    }

    // Function to delete a node from the beginning of the list
    void deleteFromBegin() {
        if (head == nullptr) {
            cout << "List is empty. Node cannot be deleted." << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;

        cout << "Node deleted from the beginning successfully." << endl;
    }

    // Function to delete a node from the end of the list
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty. Node cannot be deleted." << endl;
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            cout << "Node deleted from the end successfully." << endl;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->prev->next = nullptr;
        delete temp;

        cout << "Node deleted from the end successfully." << endl;
    }

    // Function to delete a node from a specific position in the list
    void deleteFromPosition(int position) {
        if (head == nullptr) {
            cout << "List is empty. Node cannot be deleted." << endl;
            return;
        }

        if (position <= 0) {
            cout << "Invalid position. Node cannot be deleted." << endl;
            return;
        }

        if (position == 1) {
            deleteFromBegin();
            return;
        }

        Node* temp = head;
        int count = 1;
        while (temp != nullptr && count < position) {
            temp = temp->next;
            count++;
        }

        if (temp == nullptr) {
            cout << "Invalid position. Node cannot be deleted." << endl;
            return;
        }

        temp->prev->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }
        delete temp;

        cout << "Node deleted from position " << position << " successfully." << endl;
    }

    // Function to display the doubly linked list
    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        cout << "Doubly linked list: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    int choice, value, position;

    do {
        cout << "Menu:" << endl;
        cout << "1. Insert at the beginning" << endl;
        cout << "2. Insert at the end" << endl;
        cout << "3. Insert at a specific position" << endl;
        cout << "4. Delete from the beginning" << endl;
        cout << "5. Delete from the end" << endl;
        cout << "6. Delete from a specific position" << endl;
        cout << "7. Display the list" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                dll.insertAtBegin(value);
                break;
            case 2:
                cout << "Enter the value to insert: ";
                cin >> value;
                dll.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter the value to insert: ";
                cin >> value;
                cout << "Enter the position to insert: ";
                cin >> position;
                dll.insertAtPosition(value, position);
                break;
            case 4:
                dll.deleteFromBegin();
                break;
            case 5:
                dll.deleteFromEnd();
                break;
            case 6:
                cout << "Enter the position to delete: ";
                cin >> position;
                dll.deleteFromPosition(position);
                break;
            case 7:
                dll.display();
                break;
            case 8:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    } while (choice != 8);

    return 0;
}