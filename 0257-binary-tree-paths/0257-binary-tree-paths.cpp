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
    void add(TreeNode* root, string path, vector<string>& ans) {
         if (root == NULL) {
            return;
        }
        if (root ->left == NULL && root -> right == NULL) {
            path += to_string(root -> val);
            ans.push_back(path);
            return;   
        }
        path += to_string(root -> val) + "->";
        add(root -> left, path, ans);
        add(root -> right, path, ans);

    }
    vector<string> binaryTreePaths(TreeNode* root) {
       vector<string> ans;
       string path = "";
       if (root == NULL) {
           return ans;
       }
       add(root, path, ans);
       return ans;
    }
};