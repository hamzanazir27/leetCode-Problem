class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;

        // leaf node
        if (!root->left && !root->right)
            return 1;

        // one of the subtree is NULL
        if (!root->left)
            return 1 + minDepth(root->right);

        if (!root->right)
            return 1 + minDepth(root->left);

        // both left and right exist
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};
