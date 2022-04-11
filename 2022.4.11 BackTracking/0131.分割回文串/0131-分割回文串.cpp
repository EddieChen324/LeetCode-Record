class Solution {
public:
    bool isPalindrome(const string& s, int begin, int end) {
        for (int i = begin, j = end; i < j; i++, j--) {
            if (s[i] != s[j]) return false;
        }
        return true;
    }
    vector<string> path;
    vector<vector<string>> result;
    void backTracking(string& s, int beginIndex) {
        if (beginIndex >= s.size()) {
            result.push_back(path);
            return;
        }

        for (int i = beginIndex; i < s.size(); i++) {
            if (isPalindrome(s, beginIndex, i)) {
                string str = s.substr(beginIndex, i - beginIndex + 1);
                path.push_back(str);
            }
            else continue;
            backTracking(s, i + 1);
            path.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
            backTracking(s, 0);
            return result;
    }
};