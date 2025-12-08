#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};


Node* insertBST(Node* root, int val) {
    if (root == nullptr)
        return new Node(val);

    if (val < root->data)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);

    return root;
}


bool searchBST(Node* root, int key) {
    if (root == nullptr) return false;

    if (root->data == key) return true;

    if (key < root->data)
        return searchBST(root->left, key);
    else
        return searchBST(root->right, key);
}

\
Node* findMin(Node* root) {
    while (root->left != nullptr)
        root = root->left;
    return root;
}


Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else { 
       
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

      
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}


void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = nullptr;

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values to insert into BST: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insertBST(root, x);
    }

    cout << "\nInorder Traversal: ";
    inorder(root);

    cout << "\nPreorder Traversal: ";
    preorder(root);

    cout << "\nPostorder Traversal: ";
    postorder(root);

    int key;
    cout << "\n\nEnter element to search: ";
    cin >> key;

    if (searchBST(root, key))
        cout << "Element found\n";
    else
        cout << "Element not found\n";

    cout << "Enter value to delete: ";
    cin >> key;
    root = deleteNode(root, key);

    cout << "Inorder after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
