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

   
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int leftHt = maxDepth(root->left);
        int rightHt = maxDepth(root->right);
        return max(leftHt, rightHt) + 1;
    }


    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;
        if (p->val != q->val) return false;

        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }

    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode* n1, TreeNode* n2) {
        if (n1 == nullptr && n2 == nullptr) return true;
        if (n1 == nullptr || n2 == nullptr) return false;

        return n1->val == n2->val &&
               isMirror(n1->left, n2->right) &&
               isMirror(n1->right, n2->left);
    }
};


int main() {
   
    TreeNode* root = new TreeNode(1);
    root->left  = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left  = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution sol;

    cout << "Max Depth = " << sol.maxDepth(root) << endl;
    cout << "Is Symmetric = " << (sol.isSymmetric(root) ? "Yes" : "No") << endl;
    cout << "Is Same Tree (root, root) = " << (sol.isSameTree(root, root) ? "Yes" : "No") << endl;

    return 0;
}
