class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void traversal(int k, int n, int beginIndex) {
        if (n == 0 && path.size() == k) {
            result.push_back(path);
            return;
        }
        else if (path.size() == k) return;

        for (int i = beginIndex; i <= 9 - (k - path.size()) + 1; i++) {
                path.push_back(i);
                traversal(k, n - i, i + 1);
                path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
            traversal(k, n, 1);
            return result;
    }
};