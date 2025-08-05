// // /**
// //  * Definition for a binary tree node.
// //  * struct TreeNode {
// //  *     int val;
// //  *     TreeNode *left;
// //  *     TreeNode *right;
// //  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
// //  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// //  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
// //  * right(right) {}
// //  * };
// //  */
// // class Solution {
// //     vector<int> arr;

// // public:
// //     int kthSmallest(TreeNode* root, int k) {
// //         triverse(root);
// //         sort(arr.begin(), arr.end());
// //         return arr[k-1];
// //     }

// //     TreeNode* triverse(TreeNode* node) {
// //         if (node == nullptr)
// //             return nullptr;

// //         arr.push_back(node->val);
// //         triverse(node->left);
// //         triverse(node->right);

// //         return node;
// //     }
// // };



// class Solution {
// public:
//     int count = 0;
//     int result = -1;

//     int kthSmallest(TreeNode* root, int k) {
//         inorder(root, k);
//         return result;
//     }

//     void inorder(TreeNode* node, int k) {
//         if (node == nullptr) return;

//         inorder(node->left, k);

//         count++;
//         if (count == k) {
//             result = node->val;
//             return; // early exit
//         }

//         inorder(node->right, k);
//     }
// };


class Solution {
    int count =0;
    int result=-3;
public:
    int kthSmallest(TreeNode* root, int k) {
       triverse(root,k);
       return result;
    }


    void triverse(TreeNode* node, int k)
    {
        if(node==nullptr)
           return;

        
         triverse(node->left,k);

         count++;
         if(k==count)
         {
            result=node->val;
            return ;

         }

          triverse(node->right,k);

    }
};





