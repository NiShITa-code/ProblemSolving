class Solution {
public:
    int dfs(TreeNode* root, int num) {
        if (!root) return 0;

        num = (num << 1) | root->val;

        if (!root->left && !root->right) {
            return num;
        }

        return dfs(root->left, num) + dfs(root->right, num);
    }

    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
};