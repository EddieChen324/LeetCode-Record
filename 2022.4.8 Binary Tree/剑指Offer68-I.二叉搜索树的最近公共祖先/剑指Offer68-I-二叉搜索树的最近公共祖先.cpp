/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//二叉搜索树的公共祖先就不用后序遍历了 利用二叉搜索树左小右大的特性
//为什么有返回值 因为如果根节点与p、q的关系定了 那就只有一条路可以走(二叉搜索树的特性)
class Solution {
public:
    TreeNode* traversal(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q) return root;

        //如果当前根节点比p、q都大就往左走
        if (root->val > p->val && root->val > q->val) {
            TreeNode* left = traversal(root->left, p, q);
            if (left) return left;
        }
        if (root->val < p->val && root->val < q->val) {
            TreeNode* right = traversal(root->right, p, q);
            if (right) return right;
        }
        //root节点在[p, q]value的区间中 直接返回
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            return traversal(root, p, q);
    }
};