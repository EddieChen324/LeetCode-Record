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
    void Traversal(TreeNode* root, vector<int>& result) {
        if (root == NULL) return;
        Traversal(root->left, result);
        result.push_back(root->val);
        Traversal(root->right, result);
    }
    vector<int> inorderTraversal(TreeNode* root) {
                vector<int> result;    //存放遍历结果
                Traversal(root, result);
                return result;
    }
};


//递归三要素
//1.确定递归函数的参数和返回值，首先是树的根节点，其次我们要返回它的中序遍历，就可以拿一个容器去储存，带引用参数不需要返回值
//2.确定终止条件，递归时怎样算结束了？当前遍历的节点空了，那么本层递归结束
//确定单层递归的逻辑，中序遍历，左中右的顺序去写。