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

                ////��ǰ�ڵ����target ��������һ�����ڲ��ÿ��� ������������һ��С��target,��������Ҳ����targte�Ĳ��ֽӵ�root�����
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