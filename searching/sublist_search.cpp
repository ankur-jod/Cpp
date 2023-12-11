#include <iostream>

struct Node {
    int data;
    Node* next;
};

Node* createList(int size) {
    Node* node, *start = NULL;
    for(int i = 0; i < size; i++) {
        node = new Node();
        std::cout << "Enter data for node " << i + 1 << ": ";
        std::cin >> node->data;
        node->next = NULL;

        if(start == NULL) {
            start = node;
        } else {
            Node* temp = start;
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = node;
        }
    }
    return start;
}

bool isSubList(Node* first, Node* second) {
    Node* ptr1 = first, *ptr2 = second;

    if (first == NULL && second == NULL)
        return true;

    if ( first == NULL ||
        (first != NULL && second == NULL))
        return false;

    while (first != NULL) {
        ptr1 = first;

        while (ptr2 != NULL) {
            if (ptr1 == NULL)
                return false;

            else if (ptr1->data == ptr2->data) {
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            else break;
        }

        if (ptr2 == NULL)
            return true;

        ptr2 = second;

        first = first->next;
    }

    return false;
}

int main() {
    int size1, size2;

    std::cout << "Enter the number of nodes in the first list: ";
    std::cin >> size1;
    Node* first = createList(size1);

    std::cout << "Enter the number of nodes in the second list: ";
    std::cin >> size2;
    Node* second = createList(size2);

    if(isSubList(first, second))
        std::cout << "List2 is a sublist of List1";
    else
        std::cout << "List2 is not a sublist of List1";

    return 0;
}