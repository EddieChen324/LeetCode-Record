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
    vector<TreeNode*> splitBST(TreeNode* root, int target) {
                if (!root) return {NULL, NULL};

                ////当前节点大于target 则右子树一定大于不用考虑 但是左子树不一定小于target,把左子树也大于targte的部分接到root的左边
                if (root->val > target) {
                    auto tmpRes = splitBST(root->left, target);
                    root->left = tmpRes[1];
                    return {tmpRes[0], root};
                }
                else {
                    auto tmpRes = splitBST(root->right, target);
                    root->right = tmpRes[0];
                    return {root, tmpRes[1]};
                }
                return {NULL, NULL};
    }
};