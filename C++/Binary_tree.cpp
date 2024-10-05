#include <iostream>
using namespace std;

// Define the structure of a Node
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to create a new node
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Function to insert a new node in the Binary Tree
Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);  // Create a new node if the tree is empty
    }

    // Recursively insert in the left or right subtree
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    return root;
}

// In-Order Traversal (left -> root -> right)
void inOrderTraversal(Node* root) {
    if (root != nullptr) {
        inOrderTraversal(root->left);    // Traverse left subtree
        cout << root->data << " ";       // Visit node
        inOrderTraversal(root->right);   // Traverse right subtree
    }
}

// Function to search for a value in the Binary Tree
bool search(Node* root, int key) {
    if (root == nullptr) {
        return false;  // If root is null, the value is not found
    }

    if (root->data == key) {
        return true;  // If the key is found
    } else if (key < root->data) {
        return search(root->left, key);  // Search in the left subtree
    } else {
        return search(root->right, key);  // Search in the right subtree
    }
}

int main() {
    Node* root = nullptr;  // Initializing the root of the Binary Tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout << "In-order Traversal of the Binary Tree: ";
    inOrderTraversal(root);
    cout << endl;

    int key = 40;
    if (search(root, key)) {
        cout << key << " found in the Binary Tree!" << endl;
    } else {
        cout << key << " not found in the Binary Tree!" << endl;
    }

    return 0;
}
