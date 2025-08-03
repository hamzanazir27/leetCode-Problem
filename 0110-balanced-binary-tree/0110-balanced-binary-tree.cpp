class Solution {
public:
    // Helper function: return -1 if unbalanced, else return height
    int checkHeight(TreeNode* root) {
        if (!root) return 0; // NULL node ki height 0 hoti hai

        int leftHeight = checkHeight(root->left);
        if (leftHeight == -1) return -1; // left subtree unbalanced hai

        int rightHeight = checkHeight(root->right);
        if (rightHeight == -1) return -1; // right subtree unbalanced hai

        // Agar height ka farq > 1 ho, toh unbalanced
        if (abs(leftHeight - rightHeight) > 1) return -1;

        // warna balanced hai, height return karo
        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};
