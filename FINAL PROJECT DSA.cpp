#include <iostream>
using namespace std;

// Node structure for the Mystical Tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Magic Tree Class
class MagicTree {
private:
    Node* root;

    // Recursive helper for insertion
    Node* insert(Node* node, int value) {
        if (!node) return new Node(value); // Create a new node if the current is null
        if (value < node->data) {
            node->left = insert(node->left, value); // Insert in the left subtree
        } else if (value > node->data) {
            node->right = insert(node->right, value); // Insert in the right subtree
        }
        return node;
    }

    // Recursive helper for searching
    Node* search(Node* node, int value) {
        if (!node || node->data == value) return node; // Base case: found or null
        if (value < node->data)
            return search(node->left, value); // Search in the left subtree
        return search(node->right, value);   // Search in the right subtree
    }

    // Recursive helper for finding the minimum value
    Node* findMin(Node* node) {
        while (node && node->left) {
            node = node->left; // Traverse to the leftmost node
        }
        return node;
    }

    // Recursive helper for deletion
    Node* deleteNode(Node* node, int value) {
        if (!node) return node; // Base case: node is null
        if (value < node->data) {
            node->left = deleteNode(node->left, value); // Delete in the left subtree
        } else if (value > node->data) {
            node->right = deleteNode(node->right, value); // Delete in the right subtree
        } else {
            // Node with one child or no child
            if (!node->left) {
                Node* temp = node->right;
                delete node; // Free memory
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node; // Free memory
                return temp;
            }
            // Node with two children: Get the inorder successor (minimum in the right subtree)
            Node* temp = findMin(node->right);
            node->data = temp->data; // Copy successor's value to this node
            node->right = deleteNode(node->right, temp->data); // Delete the successor
        }
        return node;
    }

    // Recursive helpers for traversals
    void preorder(Node* node) {
        if (!node) return;
        cout << node->data << " "; // Visit the root
        preorder(node->left);      // Traverse the left subtree
        preorder(node->right);     // Traverse the right subtree
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);       // Traverse the left subtree
        cout << node->data << " "; // Visit the root
        inorder(node->right);      // Traverse the right subtree
    }

    void postorder(Node* node) {
        if (!node) return;
        postorder(node->left);     // Traverse the left subtree
        postorder(node->right);    // Traverse the right subtree
        cout << node->data << " "; // Visit the root
    }

public:
    MagicTree() : root(nullptr) {}

    // Public wrappers for operations
    void insert(int value) {
        cout << "Adding " << value << " to the Mystical Tree...\n";
        root = insert(root, value); // Call the private helper
    }

    void search(int value) {
        cout << "Searching for " << value << " in the Mystical Tree...\n";
        Node* result = search(root, value); // Call the private helper
        if (result)
            cout << "The magical number " << value << " is found in the tree!\n";
        else
            cout << "The magical number " << value << " is not in the tree.\n";
    }

    void deleteNode(int value) {
        cout << "Removing " << value << " from the Mystical Tree...\n";
        root = deleteNode(root, value); // Call the private helper
    }

    void displayTraversals() {
        cout << "Exploring the Mystical Tree paths...\n";
        cout << "Preorder (Magical Seed Path): ";
        preorder(root); // Call the private helper for preorder
        cout << "\nInorder (Magical Growth Order): ";
        inorder(root); // Call the private helper for inorder
        cout << "\nPostorder (Magical Destruction Order): ";
        postorder(root); // Call the private helper for postorder
        cout << endl;
    }
};

// Main Program
int main() {
    MagicTree tree;
    int choice;

    cout << "Welcome to the Mystical Number Tree!\n";
    do {
        cout << "\nMenu:\n";
        cout << "1. Add a Magical Number\n";
        cout << "2. Search for a Magical Number\n";
        cout << "3. Remove a Magical Number\n";
        cout << "4. Explore the Mystical Tree (Traversals)\n";
        cout << "5. Exit the Magical Realm\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int value;
            cout << "Enter the magical number to add: ";
            cin >> value;
            tree.insert(value); // Add a new value to the tree
            break;
        }
        case 2: {
            int value;
            cout << "Enter the magical number to search for: ";
            cin >> value;
            tree.search(value); // Search for a value in the tree
            break;
        }
        case 3: {
            int value;
            cout << "Enter the magical number to remove: ";
            cin >> value;
            tree.deleteNode(value); // Remove a value from the tree
            break;
        }
        case 4:
            tree.displayTraversals(); // Display tree traversals
            break;
        case 5:
            cout << "Exiting the Mystical Realm. Farewell!\n"; // Exit the program
            break;
        default:
            cout << "Invalid choice! Try again.\n"; // Handle invalid input
        }
    } while (choice != 5);

    return 0;
}
