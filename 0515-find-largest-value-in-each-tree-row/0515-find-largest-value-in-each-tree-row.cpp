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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> largestEle;
        if (root == NULL) {
            return largestEle;
        }
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            int max = INT_MIN;
            while(sz--) {
                TreeNode* f = q.front();
                int data = f -> val;
                q.pop();
                if (data > max) {
                    max = data;
                }
                if (f -> left) {
                    q.push(f -> left);
                }
                if (f -> right) {
                    q.push(f -> right);
                }
            }
            largestEle.push_back(max);
        }   
        return largestEle;
    }
};