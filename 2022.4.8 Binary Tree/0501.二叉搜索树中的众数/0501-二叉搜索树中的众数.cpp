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
    int count;
    int maxCount = 0;
    vector<int> result;
    TreeNode* pre = NULL;
    void traversal(TreeNode* root) {
        if (root == NULL) return;

        traversal(root->left);
        if (!pre) count = 1;
        else if (pre && pre->val == root->val) count++;
        else count = 1;
        pre = root;    //更新前节点
        if (count == maxCount) {
            result.push_back(root->val);
        }
        else if (count > maxCount) {
            maxCount = count;
            result.clear();
            result.push_back(root->val);
        }
        traversal(root->right);   
    }
    vector<int> findMode(TreeNode* root) {
            traversal(root);
            return result;
    }
};