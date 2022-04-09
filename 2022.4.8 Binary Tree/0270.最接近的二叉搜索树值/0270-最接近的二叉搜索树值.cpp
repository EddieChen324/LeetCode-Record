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
    int result;    //最后的结果
    TreeNode* pre = NULL;
    void traversal(TreeNode* root, double target) {
        if (root == NULL) return;

        double value = abs(root->val - target);    //中
        result = root->val;    //给result初始化
        
        ////当前节点与之前的最接近节点做一个判断
        if (pre != NULL && abs(pre->val - target) < value) result = pre->val;
        else if (pre != NULL && abs(pre->val - target) > value) result = root->val;
        if (pre == NULL) pre = root;
        //如果当前节点更接近target 就将pre更新 否则不更新
        else pre = result == root->val ? root : pre;    
        if (root->val > target) traversal(root->left, target);    //左
        if (root->val < target) traversal(root->right, target);    //右
    }
    int closestValue(TreeNode* root, double target) {
            traversal(root, target);
            return result;
    }
};