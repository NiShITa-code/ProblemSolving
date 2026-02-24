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
public:
    int ans = 0;
    void dfs(TreeNode* root, int num) {
        if (!root) {
            return;
        }
        if (root -> left == nullptr && root -> right == nullptr) {
            ans += num;
            return;
        }
        if (root -> left) {
            dfs(root -> left, (num << 1)|root->left->val);
        }
        if (root -> right) {
            dfs(root -> right, (num << 1)|root ->right->val);
        }

    }
    int sumRootToLeaf(TreeNode* root) {
        ans = 0;
        dfs(root, root -> val);
        return ans;
    }
};