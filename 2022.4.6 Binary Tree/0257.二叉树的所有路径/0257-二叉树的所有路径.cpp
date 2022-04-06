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
    void traversal(TreeNode* root, string path, vector<string>& result) {
        path += to_string(root->val);
        if (!root->left && !root->right) {
            result.push_back(path);
            return;
        }
        if (root->left) traversal(root->left, path + "->", result);
        if (root->right) traversal(root->right, path + "->", result);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
            string path;
            vector<string> result;
            if (root == NULL) return result;
            traversal(root, path, result);
            return result;
    }
};