#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};


class Solution {
public:
    bool validate(TreeNode* root, TreeNode* min, TreeNode* max) {
        if (root == nullptr) {
            return true;
        }

        if (min != nullptr && root->val <= min->val) {
            return false;
        }
        if (max != nullptr && root->val >= max->val) {
            return false;
        }

        return validate(root->left, min, root)
            && validate(root->right, root, max);
    }

    bool isValidBST(TreeNode* root) {
        return validate(root, nullptr, nullptr);
    }
};


TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}


int main() {
    TreeNode* root = nullptr;

    cout << "Enter number of nodes: ";
    int n;
    cin >> n;

    cout << "Enter values: ";
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    Solution s;
    if (s.isValidBST(root))
        cout << "This is a valid BST\n";
    else
        cout << "This is NOT a valid BST\n";

    return 0;
}
