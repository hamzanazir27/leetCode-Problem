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
    int maxSum = INT_MIN;

public:
    int maxPathSum(TreeNode* root) {   dfs(root); 
        return maxSum;}

private:
    int dfs(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int maxleft = max(dfs(root->left), 0);
        int maxright = max(dfs(root->right), 0);

        int curMax = root->val + maxleft + maxright;

        maxSum = max(curMax, maxSum);

        return root->val +
               max(maxleft, maxright); /// q k main left maximum find kr raha ho
                                       /// ya right max os node tk
    }
};