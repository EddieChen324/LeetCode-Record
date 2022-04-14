class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;
    void backTracking(vector<int>& nums, int beginIndex) {
        result.push_back(path);
        if (beginIndex >= nums.size()) {
            return;
        }
        for (int i = beginIndex; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backTracking(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
            backTracking(nums, 0);
            return result;
    }
};