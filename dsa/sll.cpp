#include <iostream>

using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;
};

// Linked list class
class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() {
        head = nullptr;
    }

    // Function to insert a node at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        cout << "Node inserted successfully!" << endl;
    }

    // Function to insert a node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        cout << "Node inserted successfully!" << endl;
    }

    // Function to insert a node at any position in the list
    void insertAtPosition(int value, int position) {
        Node* newNode = new Node();
        newNode->data = value;

        if (position == 1) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            for (int i = 1; i < position - 1 && temp != nullptr; i++) {
                temp = temp->next;
            }
            if (temp == nullptr) {
                cout << "Invalid position!" << endl;
                return;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }

        cout << "Node inserted successfully!" << endl;
    }

    // Function to delete a node from the beginning of the list
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "Linked list is empty!" << endl;
        } else {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Node deleted successfully!" << endl;
        }
    }

    // Function to delete a node from the end of the list
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "Linked list is empty!" << endl;
        } else if (head->next == nullptr) {
            delete head;
            head = nullptr;
            cout << "Node deleted successfully!" << endl;
        } else {
            Node* temp = head;
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
            cout << "Node deleted successfully!" << endl;
        }
    }

    // Function to delete a node from any position in the list
    void deleteFromPosition(int position) {
        if (head == nullptr) {
            cout << "Linked list is empty!" << endl;
        } else if (position == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Node deleted successfully!" << endl;
        } else {
            Node* temp = head;
            Node* prev = nullptr;
            for (int i = 1; i < position && temp != nullptr; i++) {
                prev = temp;
                temp = temp->next;
            }
            if (temp == nullptr) {
                cout << "Invalid position!" << endl;
                return;
            }
            prev->next = temp->next;
            delete temp;
            cout << "Node deleted successfully!" << endl;
        }
    }

    // Function to reverse the linked list
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
        cout << "Linked list reversed successfully!" << endl;
    }

    // Function to swap two nodes in the linked list
    void swap(int position1, int position2) {
        if (position1 == position2) {
            cout << "Invalid positions!" << endl;
            return;
        }

        Node* prev1 = nullptr;
        Node* current1 = head;
        for (int i = 1; i < position1 && current1 != nullptr; i++) {
            prev1 = current1;
            current1 = current1->next;
        }

        Node* prev2 = nullptr;
        Node* current2 = head;
        for (int i = 1; i < position2 && current2 != nullptr; i++) {
            prev2 = current2;
            current2 = current2->next;
        }

        if (current1 == nullptr || current2 == nullptr) {
            cout << "Invalid positions!" << endl;
            return;
        }

        if (prev1 != nullptr) {
            prev1->next = current2;
        } else {
            head = current2;
        }

        if (prev2 != nullptr) {
            prev2->next = current1;
        } else {
            head = current1;
        }

        Node* temp = current1->next;
        current1->next = current2->next;
        current2->next = temp;

        cout << "Nodes swapped successfully!" << endl;
    }

    // Function to display the linked list
    void display() {
        if (head == nullptr) {
            cout << "Linked list is empty!" << endl;
        } else {
            Node* temp = head;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    LinkedList list;
    int choice, value, position1, position2;

    do {
        cout << "Menu:" << endl;
        cout << "1. Insert at the beginning" << endl;
        cout << "2. Insert at the end" << endl;
        cout << "3. Insert at any position" << endl;
        cout << "4. Delete from the beginning" << endl;
        cout << "5. Delete from the end" << endl;
        cout << "6. Delete from any position" << endl;
        cout << "7. Reverse the list" << endl;
        cout << "8. Swap two nodes" << endl;
        cout << "9. Display the list" << endl;
        cout << "10. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                list.insertAtBeginning(value);
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
                cin >> position1;
                list.insertAtPosition(value, position1);
                break;
            case 4:
                list.deleteFromBeginning();
                break;
            case 5:
                list.deleteFromEnd();
                break;
            case 6:
                cout << "Enter the position: ";
                cin >> position1;
                list.deleteFromPosition(position1);
                break;
            case 7:
                list.reverse();
                break;
            case 8:
                cout << "Enter the positions of the nodes to swap: ";
                cin >> position1 >> position2;
                list.swap(position1, position2);
                break;
            case 9:
                list.display();
                break;
            case 10:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    } while (choice != 10);

    return 0;
}