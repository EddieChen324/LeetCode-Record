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
    int result;    //���Ľ��
    TreeNode* pre = NULL;
    void traversal(TreeNode* root, double target) {
        if (root == NULL) return;

        double value = abs(root->val - target);    //��
        result = root->val;    //��result��ʼ��
        
        ////��ǰ�ڵ���֮ǰ����ӽ��ڵ���һ���ж�
        if (pre != NULL && abs(pre->val - target) < value) result = pre->val;
        else if (pre != NULL && abs(pre->val - target) > value) result = root->val;
        if (pre == NULL) pre = root;
        //�����ǰ�ڵ���ӽ�target �ͽ�pre���� ���򲻸���
        else pre = result == root->val ? root : pre;    
        if (root->val > target) traversal(root->left, target);    //��
        if (root->val < target) traversal(root->right, target);    //��
    }
    int closestValue(TreeNode* root, double target) {
            traversal(root, target);
            return result;
    }
};