/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//�����������Ĺ������ȾͲ��ú�������� ���ö�����������С�Ҵ������
//Ϊʲô�з���ֵ ��Ϊ������ڵ���p��q�Ĺ�ϵ���� �Ǿ�ֻ��һ��·������(����������������)
class Solution {
public:
    TreeNode* traversal(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q) return root;

        //�����ǰ���ڵ��p��q�����������
        if (root->val > p->val && root->val > q->val) {
            TreeNode* left = traversal(root->left, p, q);
            if (left) return left;
        }
        if (root->val < p->val && root->val < q->val) {
            TreeNode* right = traversal(root->right, p, q);
            if (right) return right;
        }
        //root�ڵ���[p, q]value�������� ֱ�ӷ���
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            return traversal(root, p, q);
    }
};