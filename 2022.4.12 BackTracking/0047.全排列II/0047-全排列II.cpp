class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backTracking(vector<int>& nums, vector<bool>& used) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        unordered_set<int> uset;
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == true || uset.find(nums[i]) != uset.end()) continue;
            path.push_back(nums[i]);
            uset.insert(nums[i]);
            used[i] = true;
            backTracking(nums, used);
            used[i] = false;
            path.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
            vector<bool> used(nums.size(), false);
            backTracking(nums, used);
            return result;
    }
};