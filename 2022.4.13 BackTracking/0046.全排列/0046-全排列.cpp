class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backTracking(vector<int>& nums, vector<bool>& used) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == true) continue;
            used[i] = true;
            path.push_back(nums[i]);
            backTracking(nums,used);
            used[i] =false;
            path.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
            vector<bool> used(nums.size(), false);
            backTracking(nums, used);
            return result;
    }
};