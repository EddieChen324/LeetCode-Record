class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;
    void backTracking(vector<int>& candidates, int target, int beginIndex, vector<bool>& used) {
        if (target == 0) {
            result.push_back(path);
            return;
        }
        for (int i = beginIndex; i < candidates.size() && target - candidates[i] >= 0; i++) {
            if (i > 0 && used[i - 1] == false && candidates[i] == candidates[i - 1]) continue;
            path.push_back(candidates[i]);
            used[i] = true;
            backTracking(candidates, target - candidates[i], i + 1, used);
            path.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            vector<bool> used(candidates.size(), false);
            sort(candidates.begin(), candidates.end());
            backTracking(candidates, target, 0, used);
            return result;
    }
};