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
    vector<int> arr;
public:
    vector<int> inorderTraversal(TreeNode* root) {
     
        pusharr(root);
        return arr;
         
    }


    void  pusharr(TreeNode* node)
    {
        if(node==nullptr)
          return ;
       
       pusharr(node->left);
       arr.push_back(node->val);
       pusharr(node->right);
       
        
    }
};