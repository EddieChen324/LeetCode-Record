class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;
    void backTracking(vector<int>& candidates, int sum, int beginIndex) {
        if (sum < 0) return;
        if (sum == 0) {
            result.push_back(path);
        }

        for (int i = beginIndex; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            backTracking(candidates, sum - candidates[i], i);    //不用i+1重复读取当前数字
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
                backTracking(candidates, target, 0);
                return result;
    }
};

////求同一个集合的不同组合 startIndex 表明从它开始遍历  求不同集合的不同组合 startIndex表明进入下一个集合