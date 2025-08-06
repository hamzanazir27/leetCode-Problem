/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // ager p aur q root se chotey ahi tu 
        if((root->val > p->val ) && (root->val >q->val))
        {
           return lowestCommonAncestor(root->left ,p,q);
        }        
        // ager p aur q root se chotey ahi tu 
        if((root->val < p->val ) && (root->val <q->val))
        {
           return lowestCommonAncestor(root->right ,p,q);
        }        

        //jb is ye p ka b parent ye hi hai aur q k pareent b ye hi hai aur p air q equal nhi hai
        return root;
    }
};