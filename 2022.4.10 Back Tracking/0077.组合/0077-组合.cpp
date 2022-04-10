class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backTracking(int n, int k, int beginIndex) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        for (int i = beginIndex; i <= n - (k - path.size()) + 1; i++) {
            path.push_back(i);
            backTracking(n, k, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
            backTracking(n, k, 1);
            return result;
    }
};