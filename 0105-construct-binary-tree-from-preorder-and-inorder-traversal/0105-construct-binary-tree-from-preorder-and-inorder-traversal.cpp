class Solution {
public:
    unordered_map<int, int> inorderMap;  // value -> index in inorder
    int preorderIndex = 0;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Step 1: Create hashmap for inorder for O(1) lookup
        for (int i = 0; i < inorder.size(); ++i) {
            inorderMap[inorder[i]] = i;
        }

        // Step 2: Call recursive helper
        return buildSubtree(preorder, 0, inorder.size() - 1);
    }

    TreeNode* buildSubtree(const vector<int>& preorder, int left, int right) {
        // Base Case: No subtree
        if (left > right)
            return nullptr;

        // Step 3: Get current root value from preorder
        int rootVal = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootVal);

        // Step 4: Find root index in inorder
        int mid = inorderMap[rootVal];

        // Step 5: Recursively build left and right subtree
        root->left = buildSubtree(preorder, left, mid - 1);
        root->right = buildSubtree(preorder, mid , right);

        return root;
    }
};
