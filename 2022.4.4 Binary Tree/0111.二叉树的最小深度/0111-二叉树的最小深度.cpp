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
//     int minDepth(TreeNode* root) {
//         queue<TreeNode*> que;
//         int depth = 0;
//         if (root != NULL) que.push(root);
//         bool flag = true;
//         while (!que.empty() && flag) {
//             int size = que.size();
//             depth++;
//             for (int i = 0; i < size; i++) {
//                 TreeNode* node = que.front();
//                 que.pop();
//                 if (node->left == NULL && node->right == NULL) {
//                     flag = false;    //˵���Ѿ��ҵ���Ҫ�ҵĽڵ㣬��������������
//                     break;    //���̽���forѭ��
//                 }
//                 if (node->left) que.push(node->left);
//                 if (node->right) que.push(node->right);
//             }
//         }
//         return depth;
//     }
// };

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int depth = 0;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            int size = que.size();
            depth++; // ��¼��С���
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
                if (!node->left && !node->right) { // �����Һ��Ӷ�Ϊ�յ�ʱ��˵������͵��һ���ˣ��˳�
                    return depth;
                }
            }
        }
        return depth;
    }
};