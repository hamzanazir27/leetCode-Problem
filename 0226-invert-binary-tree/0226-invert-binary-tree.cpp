/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr)
           return nullptr;

        invert(root);
        return root;
        
    }

    TreeNode* invert(TreeNode* node)
    {
      if(node==nullptr)
           return nullptr;

        TreeNode* lefts=node->left;
        node->left = node->right;
        node->right=lefts;


        invert(node->left);
        invert(node->right);
        return node;
    }

};