class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;
    void backTracking(int k, int n, int beginIndex, int count) {
        if (count < 0) return;
        if (path.size() == k && count == 0) {
            result.push_back(path);
            return;
        }
        
        for (int i = beginIndex; i <= 9 - (k - path.size()) + 1; i++) {
            path.push_back(i);
            backTracking(k, n, i + 1, count - i);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
            backTracking(k, n, 1, n);
            return result;
    }
};