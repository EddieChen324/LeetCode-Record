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
    TreeNode* traversal(vector<int>& preorder, int preorderBegin, int preorderEnd, vector<int>& inorder, int inorderBegin, int inorderEnd) {
        if (preorderBegin == preorderEnd) return NULL;

        int rootValue = preorder[preorderBegin];
        TreeNode* root = new TreeNode(rootValue);

        if (preorderEnd - preorderBegin - 1 == 0) return root;

        //找到根节点在中序数组的位置
        int delimiterIndex;
        for(delimiterIndex = inorderBegin; delimiterIndex < inorderEnd; delimiterIndex++) {
            if (inorder[delimiterIndex] == rootValue) break;
        }

        //切割中序数组
        int leftInorderBegin = inorderBegin;
        int leftInorderEnd = delimiterIndex;
        int rightInorderBegin = delimiterIndex + 1;
        int rightInorderEnd = inorderEnd;

        //切割前序数组
        int leftPreorderBegin = preorderBegin + 1;
        int leftPreorderEnd =  preorderBegin + 1 + delimiterIndex -leftInorderBegin;
        int rightPreorderBegin = leftPreorderEnd;
        int rightPreorderEnd = preorderEnd;

        root->left = traversal(preorder, leftPreorderBegin, leftPreorderEnd, inorder, leftInorderBegin, leftInorderEnd);
        root->right = traversal(preorder, rightPreorderBegin, rightPreorderEnd, inorder, rightInorderBegin, rightInorderEnd);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            if (preorder.size() == 0 || inorder.size() == 0) return NULL;
            TreeNode* root = traversal(preorder, 0, preorder.size(), inorder, 0, inorder.size());
            return root;
    }
};