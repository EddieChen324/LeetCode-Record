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
    TreeNode* deleteNode(TreeNode* root, int key) {
                ////��һ����� û�ҵ�ɾ���Ľڵ�ֱ�ӷ�����
                if (root == NULL) return NULL;
                ////�ҵ��ڵ�� ����4�����
                if (root->val == key) {
                    ////��һ�ָýڵ�û���������Һ��� �򷵻������Һ���
                    if (!root->left && root->right) {
                        TreeNode* res = root->right;
                        delete root;
                        return res;
                    }
                    ////�ڶ������������û���Һ��ӣ��򷵻���������
                    if (!root->right && root->left) {
                        TreeNode* res = root->left;
                        delete root;
                        return res;
                    }
                    ////��������������Һ��Ӷ�û�� ��ɾ���ýڵ㷵��NULL
                    if (!root->left && !root->right) {
                        delete root;
                        return NULL;
                    }
                    ////��������������Һ��Ӷ��� ���Һ��ӵ�����ڵ�ָ������
                    if (root->left && root->right) {
                        TreeNode* cur =root->right;
                        while (cur->left) {
                            cur = cur->left;    //�ҵ������������һ����ڵ�
                        }
                        cur->left = root->left;
                        TreeNode* tmp = root;
                        root = root->right;
                        delete tmp;
                        return root;
                    }
                }
                if (root->val < key) root->right = deleteNode(root->right, key);
                else if (root->val > key) root->left = deleteNode(root->left, key);
                return root;
    }
};