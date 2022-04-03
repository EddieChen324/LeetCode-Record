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

// class Solution {
// public:
//     vector<int> rightSideView(TreeNode* root) {
//         vector<int> result;    //每一层只放一个元素 每一层左侧的元素先全部弹出去
//         queue<TreeNode*> que;
//         if (root != NULL) que.push(root);
//         while (!que.empty()) {
//             int size = que.size();
//             vector<int> vec;
//             for (int i = 0; i < size; i++) {
//                 TreeNode* node = que.front();
//                 que.pop();
//                 vec.push_back(node->val);
//                 if (node->left) que.push(node->left);
//                 if (node->right) que.push(node->right);
//             }
//             result.push_back(vec[size - 1]);
//         }
//         return result;
//     }
// };

class Solution {
    public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> que;
        if (root != NULL) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (i == size - 1) result.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return result;
    }
};