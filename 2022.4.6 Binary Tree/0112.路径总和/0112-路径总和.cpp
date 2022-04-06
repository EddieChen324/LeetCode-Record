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
    void Traversal(TreeNode* root, vector<int>& path, vector<int>& result) {
        path.push_back(root->val);
        if (!root->left && !root->right) {
            int sum = 0;
            for (int i = 0; i < path.size(); i++) {
                sum += path[i];
            }
            result.push_back(sum);
            return;
        }
        if (root->left) {
            Traversal(root->left, path, result);
            path.pop_back();
        }
        if (root->right) {
            Traversal(root->right, path, result);
            path.pop_back();
        }
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
            if (root == NULL) return 0;
            vector<int> path;
            vector<int> result;
            Traversal(root, path, result);
            for (int i = 0; i < result.size(); i++) {
                if (result[i] == targetSum) return true;
            }
            return false;
    }
};