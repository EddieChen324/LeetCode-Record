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

 ////前序遍历 遍历所有路径 不需要返回值 定义两个全局变量
class Solution {
public:
    vector<vector<int>> result;    //储存所有路径
    vector<int> vec;    //每一条路径
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