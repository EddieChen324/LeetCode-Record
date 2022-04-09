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
    TreeNode* traversal(vector<int>& nums, int begin, int end) {
        if (begin > end) return NULL;

        int middle = begin + (end - begin) / 2;    //·ÀÖ¹Òç³ö
        TreeNode* root = new TreeNode(nums[middle]);
        root->left = traversal(nums, begin, middle - 1);
        root->right = traversal(nums, middle + 1, end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
            return traversal(nums, 0, nums.size() - 1);
    }
};