#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        this->data = val;
        left = right = NULL;
    }
};

static int idx = -1;


Node* buildTree(vector<int>& nodes) {
    idx++;
    if (idx >= nodes.size() || nodes[idx] == -1) {
        return NULL;
    }

    Node* newNode = new Node(nodes[idx]);
    newNode->left = buildTree(nodes);
    newNode->right = buildTree(nodes);

    return newNode;
}


void printLevelOrder(Node* root) {
    if (!root) { 
        cout << "Empty Tree\n"; 
        return; 
    }

    vector<Node*> q;
    q.push_back(root);

    int i = 0;
    while (i < q.size()) {
        Node* curr = q[i++];
        if (curr) {
            cout << curr->data << " ";
            q.push_back(curr->left);
            q.push_back(curr->right);
        }
    }
    cout << endl;
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(nodes);

    cout << "Level Order Traversal: ";
    printLevelOrder(root);

    return 0;
}
