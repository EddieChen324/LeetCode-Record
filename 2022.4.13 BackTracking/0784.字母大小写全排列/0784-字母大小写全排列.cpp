class Solution {
public:
    vector<string> result;
    string path;
    void backTracking(string& s, int startIndex) {
        if (path.size() == s.size()) {
            result.push_back(path);
            return;
        }
        if (isalpha(s[startIndex])) {
            path += s[startIndex];
            backTracking(s, startIndex + 1);
            path.pop_back();
            path += s[startIndex] > 96 ? s[startIndex] -32 : s[startIndex] + 32;
            backTracking(s, startIndex + 1);
            path.pop_back();
        }
        else {
            path += s[startIndex];
            backTracking(s, startIndex + 1);
            path.pop_back();
        }
    }
    vector<string> letterCasePermutation(string s) {
                backTracking(s, 0);
                return result;
    }
};