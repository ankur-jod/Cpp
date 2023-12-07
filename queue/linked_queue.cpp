#include <iostream>

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        std::cout << "Enqueued " << value << " to the queue." << std::endl;
    }

    void dequeue() {
        if (front == nullptr) {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
        } else {
            Node* temp = front;
            front = front->next;

            if (front == nullptr) {
                rear = nullptr;
            }

            std::cout << "Dequeued " << temp->data << " from the queue." << std::endl;
            delete temp;
        }
    }

    void display() {
        if (front == nullptr) {
            std::cout << "Queue is empty." << std::endl;
        } else {
            Node* temp = front;
            std::cout << "Queue: ";
            while (temp != nullptr) {
                std::cout << temp->data << " ";
                temp = temp->next;
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Queue queue;
    int choice, value;

    do {
        std::cout << "1. Enqueue" << std::endl;
        std::cout << "2. Dequeue" << std::endl;
        std::cout << "3. Display" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter the value to enqueue: ";
                std::cin >> value;
                queue.enqueue(value);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                queue.display();
                break;
            case 4:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
