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
public:
    bool isSymmetric(TreeNode* root) {
        // if(root==nullptr)
        return isSameNode(root->left, root->right);
    }

    bool isSameNode(TreeNode* leftNode, TreeNode* rightNode) {
        if (!leftNode && !rightNode)
            return true;

      if (!leftNode  || !rightNode)
            return false;

        if (leftNode->val != rightNode->val)
            return false;

 ;


        return isSameNode(leftNode->left,rightNode->right) && isSameNode(leftNode->right,rightNode->left);
    }
};