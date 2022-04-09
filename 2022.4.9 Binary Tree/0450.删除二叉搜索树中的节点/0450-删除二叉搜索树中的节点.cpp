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
                ////第一种情况 没找到删除的节点直接返回了
                if (root == NULL) return NULL;
                ////找到节点后 又有4种情况
                if (root->val == key) {
                    ////第一种该节点没有左孩子有右孩子 则返回它的右孩子
                    if (!root->left && root->right) {
                        TreeNode* res = root->right;
                        delete root;
                        return res;
                    }
                    ////第二种情况有左孩子没有右孩子，则返回它的左孩子
                    if (!root->right && root->left) {
                        TreeNode* res = root->left;
                        delete root;
                        return res;
                    }
                    ////第三种情况左孩子右孩子都没有 则删除该节点返回NULL
                    if (!root->left && !root->right) {
                        delete root;
                        return NULL;
                    }
                    ////第四种情况左孩子右孩子都有 则右孩子的最左节点指向左孩子
                    if (root->left && root->right) {
                        TreeNode* cur =root->right;
                        while (cur->left) {
                            cur = cur->left;    //找到右子树的最后一个左节点
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