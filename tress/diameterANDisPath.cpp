#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


TreeNode* buildTree(vector<int>& arr) {
    if (arr.size() == 0 || arr[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < arr.size()) {
        TreeNode* curr = q.front();
        q.pop();

        
        if (arr[i] != -1) {
            curr->left = new TreeNode(arr[i]);
            q.push(curr->left);
        }
        i++;

        if (i >= arr.size()) break;

        
        if (arr[i] != -1) {
            curr->right = new TreeNode(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}


class Solution {
public:
    
    int height(TreeNode* root) {
        if (!root) return 0;
        return max(height(root->left), height(root->right)) + 1;
    }

   
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        int currDia = height(root->left) + height(root->right);
        int leftDia = diameterOfBinaryTree(root->left);
        int rightDia = diameterOfBinaryTree(root->right);

        return max(currDia, max(leftDia, rightDia));
    }

   
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        
        if (!root->left && !root->right)
            return targetSum == root->val;

        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
};


int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter tree nodes (level order, -1 for null):\n";
    vector<int> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    TreeNode* root = buildTree(arr);

    Solution sol;

    cout << "\nDiameter of Binary Tree = " << sol.diameterOfBinaryTree(root) << endl;

    int target;
    cout << "Enter target sum: ";
    cin >> target;

    if (sol.hasPathSum(root, target))
        cout << "Path Exists\n";
    else
        cout << "No Path Found\n";

    return 0;
}
