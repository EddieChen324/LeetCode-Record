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

 ////ǰ����� ��������·�� ����Ҫ����ֵ ��������ȫ�ֱ���
class Solution {
public:
    vector<vector<int>> result;    //��������·��
    vector<int> vec;    //ÿһ��·��
    void traversal(TreeNode* root, int count) {
        if (!root->left && !root->right && count == 0) {
            result.push_back(vec);
            return;
        }
        if (root->left) {
            vec.push_back(root->left->val);
            traversal(root->left, count - root->left->val);
            vec.pop_back();
        }
        if (root->right) {
            vec.push_back(root->right->val);
            traversal(root->right, count - root->right->val);
            vec.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
            if (root == NULL) return result;
            vec.push_back(root->val);
            traversal(root, targetSum - root->val);
            return result;
    }
};