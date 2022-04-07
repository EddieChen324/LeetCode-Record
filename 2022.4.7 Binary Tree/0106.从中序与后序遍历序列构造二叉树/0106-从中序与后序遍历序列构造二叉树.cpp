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
    TreeNode* traversal(vector<int>& inorder, int inorderBegin, int inorderEnd, vector<int>& postorder, int postorderBegin, int postorderEnd) {
        if (postorderBegin == postorderEnd) return NULL;

        TreeNode* root = new TreeNode(postorder[postorderEnd - 1]);
        if (postorderEnd - postorderBegin == 1) return root;

        //�ҵ����ڵ������������λ��
        int delimiterIndex;
        for (delimiterIndex = inorderBegin; delimiterIndex < inorderEnd; delimiterIndex++) {
            if (inorder[delimiterIndex] == postorder[postorderEnd - 1]) break;
        }
        //�ָ���������    ����ҿ�
        int leftInorderBegin = inorderBegin;
        int leftInorderEnd = delimiterIndex;
        int rightInorderBegin = delimiterIndex + 1;
        int rightInorderEnd = inorderEnd;

        //�ָ��������
        int leftPostorderBegin = postorderBegin;
        //����λ��Ϊ��������ʼλ�ü��������������С
        int leftPostorderEnd = leftPostorderBegin + (delimiterIndex - inorderBegin);
        int rightPostorderBegin = leftPostorderEnd;
        int rightPostorderEnd = postorderEnd - 1;    //�ų����һ��Ԫ��

        root->left = traversal(inorder, leftInorderBegin, leftInorderEnd, postorder, leftPostorderBegin, leftPostorderEnd);
        root->right = traversal(inorder, rightInorderBegin, rightInorderEnd, postorder, rightPostorderBegin, rightPostorderEnd);

        return root;    
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root = traversal(inorder, 0, inorder.size(), postorder, 0, postorder.size());
        return root;
    }
};