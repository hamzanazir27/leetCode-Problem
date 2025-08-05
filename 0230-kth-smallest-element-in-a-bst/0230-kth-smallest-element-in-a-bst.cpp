/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    vector<int> arr;

public:
    int kthSmallest(TreeNode* root, int k) {
        triverse(root);
        sort(arr.begin(), arr.end());
        return arr[k-1];
    }

    TreeNode* triverse(TreeNode* node) {
        if (node == nullptr)
            return nullptr;

        arr.push_back(node->val);
        triverse(node->left);
        triverse(node->right);

        return node;
    }
};