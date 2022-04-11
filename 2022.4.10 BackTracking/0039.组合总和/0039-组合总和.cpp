class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backTracking(vector<int>& candidates, int target, int beginIndex, int sum) {
        if (sum == target) {
            result.push_back(path);
            return;
        }
        for (int i = beginIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            path.push_back(candidates[i]);
            backTracking(candidates, target, i, sum + candidates[i]);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            sort(candidates.begin(), candidates.end());
            backTracking(candidates, target, 0, 0);
            return result;
    }
};