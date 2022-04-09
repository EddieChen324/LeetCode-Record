/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //后序遍历 保证最深  左右中    有返回值
class Solution {
public:
    TreeNode* traversal(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL | root == p || root == q) return root;

        TreeNode* left = traversal(root->left, p, q);
        TreeNode* right = traversal(root->right, p, q);

        if (left && right) return root;
        else if (left && !right) return left;
        else if (!left && right) return right;
        else return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return traversal(root, p ,q);
    }
};