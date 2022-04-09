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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
            if (root == NULL) return root;

            ////�����ǰ���ڵ㶼С����Сֵ ���������Ӿͼ���
            if (root->val < low) {
                TreeNode* right = trimBST(root->right, low, high);
                return right;
            }
            else if (root->val > high) {
                TreeNode* left = trimBST(root->left, low, high);
                return left;
            }
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
            return root;
    }
};