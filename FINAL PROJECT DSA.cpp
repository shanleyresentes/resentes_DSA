#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Node Structure for MagicTree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// MagicTree Implementation
class MagicTree {
private:
    Node* root;

    Node* insert(Node* node, int value) {
        if (!node) return new Node(value);
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }
        return node;
    }

    Node* search(Node* node, int value) {
        if (!node || node->data == value) return node;
        if (value < node->data)
            return search(node->left, value);
        return search(node->right, value);
    }

    Node* findMin(Node* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }

    Node* deleteNode(Node* node, int value) {
        if (!node) return node;
        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        } else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        } else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    void preorder(Node* node) {
        if (!node) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void postorder(Node* node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

public:
    MagicTree() : root(nullptr) {}

    void insert(int value) {
        cout << "Adding " << value << " to the Mystical Tree...\n";
        root = insert(root, value);
    }

    void search(int value) {
        cout << "Searching for " << value << " in the Mystical Tree...\n";
        Node* result = search(root, value);
        if (result)
            cout << "The magical number " << value << " is found in the tree!\n";
        else
            cout << "The magical number " << value << " is not in the tree.\n";
    }

    void deleteNode(int value) {
        cout << "Removing " << value << " from the Mystical Tree...\n";
        root = deleteNode(root, value);
    }

    void displayTraversals() {
        cout << "Exploring the Mystical Tree paths...\n";
        cout << "Preorder (Magical Seed Path): ";
        preorder(root);
        cout << "\nInorder (Magical Growth Order): ";
        inorder(root);
        cout << "\nPostorder (Magical Destruction Order): ";
        postorder(root);
        cout << endl;
    }
};

// MinHeap Implementation
class MinHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[parent] > heap[index]) {
                swap(heap[parent], heap[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        while (2 * index + 1 < size) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;

            if (left < size && heap[left] < heap[smallest]) {
                smallest = left;
            }

            if (right < size && heap[right] < heap[smallest]) {
                smallest = right;
            }

            if (smallest != index) {
                swap(heap[index], heap[smallest]);
                index = smallest;
            } else {
                break;
            }
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
        cout << "Added " << value << " to the Min Heap.\n";
    }

    void remove() {
        if (heap.empty()) {
            cout << "Min Heap is empty!\n";
            return;
        }
        cout << "Removed " << heap[0] << " from the Min Heap.\n";
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    void displaySorted() {
        vector<int> sorted = heap;
        sort(sorted.begin(), sorted.end());
        cout << "Min Heap contents (sorted): ";
        for (int val : sorted) {
            cout << val << " ";
        }
        cout << endl;
    }
};

// MaxHeap Implementation
class MaxHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[parent] < heap[index]) {
                swap(heap[parent], heap[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        while (2 * index + 1 < size) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < size && heap[left] > heap[largest]) {
                largest = left;
            }

            if (right < size && heap[right] > heap[largest]) {
                largest = right;
            }

            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
        cout << "Added " << value << " to the Max Heap.\n";
    }

    void remove() {
        if (heap.empty()) {
            cout << "Max Heap is empty!\n";
            return;
        }
        cout << "Removed " << heap[0] << " from the Max Heap.\n";
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    void displaySorted() {
        vector<int> sorted = heap;
        sort(sorted.rbegin(), sorted.rend());
        cout << "Max Heap contents (sorted): ";
        for (int val : sorted) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    MagicTree tree;
    MinHeap minHeap;
    MaxHeap maxHeap;
    int choice;

    cout << "Welcome to the Mystical Number Tree and Heap!\n";
    do {
        cout << "\nMenu:\n";
        cout << "1. Add a Magical Number to the Tree (also adds to Min and Max Heaps)\n";
        cout << "2. Search for a Magical Number in the Tree\n";
        cout << "3. Remove a Magical Number from the Tree\n";
        cout << "4. Explore the Mystical Tree (Traversals)\n";
        cout << "5. Display Min Heap (sorted)\n";
        cout << "6. Display Max Heap (sorted)\n";
        cout << "7. Exit the Magical Realm\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int value;
            cout << "Enter the magical number to add: ";
            cin >> value;
            tree.insert(value);
            minHeap.insert(value);
            maxHeap.insert(value);
            break;
        }
        case 2: {
            int value;
            cout << "Enter the magical number to search for in the tree: ";
            cin >> value;
            tree.search(value);
            break;
        }
        case 3: {
            int value;
            cout << "Enter the magical number to remove from the tree: ";
            cin >> value;
            tree.deleteNode(value);
            break;
        }
        case 4:
            tree.displayTraversals();
            break;
        case 5:
            minHeap.displaySorted();
            break;
        case 6:
            maxHeap.displaySorted();
            break;
        case 7:
            cout << "Exiting the Magical Realm. Farewell!\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
