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
    vector<double> averageOfLevels(TreeNode* root) {
            vector<double> result;    //存放每一层的平均值
            queue<TreeNode*> que;
            if (root != NULL) que.push(root);
            while (!que.empty()) {
                int size = que.size();
                double mean = 0;
                for (int i = 0; i < size; i++) {
                    TreeNode* node = que.front();
                    que.pop();
                    mean += node->val;
                    if (node->left) que.push(node->left);
                    if (node->right) que.push(node->right);
                }
                mean = mean / size;
                result.push_back(mean);
            }
            return result;
    }
};