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
    int getHeight(TreeNode* root) {
        if (root == NULL) return true;
        int leftHeight = getHeight(root->left);
        if (leftHeight == -1) return -1;
        int rightHeight = getHeight(root->right);
        if (rightHeight == -1) return -1;

        if (abs(leftHeight - rightHeight) > 1) {
            return -1;
        }
        else return 1 + max(leftHeight, rightHeight);
    }
    bool isBalanced(TreeNode* root) {
        int height = getHeight(root);
        bool result;
        return result = height != -1 ? true : false;
    }
};