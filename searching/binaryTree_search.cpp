#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }

    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    }

    return root;
}

Node* search(Node* root, int key) {
    if (root == nullptr || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

int main() {
    Node* root = nullptr;

    int n;
    std::cout << "Enter the number of nodes: ";
    std::cin >> n;

    std::cout << "Enter the values of the nodes: ";
    for (int i = 0; i < n; i++) {
        int value;
        std::cin >> value;
        root = insert(root, value);
    }

    int key;
    std::cout << "Enter the key to search: ";
    std::cin >> key;

    Node* result = search(root, key);

    if (result != nullptr) {
        std::cout << "Element " << key << " found in the binary tree." << std::endl;
    } else {
        std::cout << "Element " << key << " not found in the binary tree." << std::endl;
    }

    return 0;
}
