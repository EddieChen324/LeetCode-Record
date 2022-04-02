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

 //�ݹ�д��
// class Solution {
// public:
//     void Traversal(TreeNode* root, vector<int>& result) {
//         if (root == NULL) return;
//         result.push_back(root->val);    //��
//         Traversal(root->left, result);    //��
//         Traversal(root->right, result);    //��
//     }
//     vector<int> preorderTraversal(TreeNode* root) {
//                 vector<int> result;
//                 Traversal(root, result);
//                 return result;
//     }
// };

//����д��
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
                stack<TreeNode*> st;
                vector<int> result;
                if (root == NULL) return result;
                st.push(root);
                while (!st.empty()) {
                    TreeNode* node = st.top();
                    st.pop();
                    result.push_back(node->val);
                    if (node->right) st.push(node->right);
                    if (node->left) st.push(node->left);
                }
                return result;
    }
};