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

        //找到根节点在中序数组的位置
        int delimiterIndex;
        for (delimiterIndex = inorderBegin; delimiterIndex < inorderEnd; delimiterIndex++) {
            if (inorder[delimiterIndex] == postorder[postorderEnd - 1]) break;
        }
        //分割中序数组    左闭右开
        int leftInorderBegin = inorderBegin;
        int leftInorderEnd = delimiterIndex;
        int rightInorderBegin = delimiterIndex + 1;
        int rightInorderEnd = inorderEnd;

        //分割后序数组
        int leftPostorderBegin = postorderBegin;
        //结束位置为该数组起始位置加上中序左数组大小
        int leftPostorderEnd = leftPostorderBegin + (delimiterIndex - inorderBegin);
        int rightPostorderBegin = leftPostorderEnd;
        int rightPostorderEnd = postorderEnd - 1;    //排除最后一个元素

        root->left = traversal(inorder, leftInorderBegin, leftInorderEnd, postorder, leftPostorderBegin, leftPostorderEnd);
        root->right = traversal(inorder, rightInorderBegin, rightInorderEnd, postorder, rightPostorderBegin, rightPostorderEnd);

        return root;    
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root = traversal(inorder, 0, inorder.size(), postorder, 0, postorder.size());
        return root;
    }
};