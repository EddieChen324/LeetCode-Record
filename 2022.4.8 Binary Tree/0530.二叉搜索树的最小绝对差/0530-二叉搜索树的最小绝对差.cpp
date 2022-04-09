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

 ////���������� ������������ǵ���������
class Solution {
public:
    TreeNode* pre = NULL;
    int result = INT32_MAX;
    void traversal(TreeNode* root) {
        if (root == NULL) return;

        traversal(root->left);
        if (pre) result = min(result, root->val - pre->val);
        pre = root;
        traversal(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
            traversal(root);
            return result;
    }
};