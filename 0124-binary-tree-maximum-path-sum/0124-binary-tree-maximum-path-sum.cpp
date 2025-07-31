/**
*
*
*

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
 *
 *
 *
 *
 *
 */
class Solution {
    int maxSum=INT_MIN;

public:
    int maxPathSum(TreeNode* root) {  
       
           
     bfs(root);
     return maxSum;




        }



private :
     int bfs(TreeNode* node)
     {
        if(node==nullptr)
        {
            return 0;
        }

      int maxleft=max(bfs(node->left),0);  //9 //15 
      int maxright=max(bfs(node->right),0);//20
      int curSum =node->val+maxleft+maxright;//[-10+9+20=1]
      maxSum=max(maxSum,curSum);//   <-9    //[]

      return node->val+max(maxleft,maxright);//

      

     }

};