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
    TreeNode* traversal(vector<int>& nums, int left, int right) {
        if (left >= right) return NULL;

        int maxValueIndex = left;
        for (int i =left + 1; i < right; i++) {
            if (nums[i] > nums[maxValueIndex]) maxValueIndex = i;
        }
        TreeNode* root = new TreeNode(nums[maxValueIndex]);

        root->left = traversal(nums, left, maxValueIndex);
        root->right = traversal(nums, maxValueIndex + 1, right);

        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) { 
            return traversal(nums, 0, nums.size());
    }
};