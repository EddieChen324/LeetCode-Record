class Solution {
public:
    vector<string> result;

    bool is_valid(const string& s, int begin, int end) {
        if (begin > end) return false;
        if (s[begin] == '0' && begin != end) return false;
        int num = 0;
        for (int i = begin; i <= end; i++) {
            if (s[i] > '9' || s[i] < '0') {
                return false;
            }
            num = num * 10 + (s[i] - '0');
            if (num > 255) {
                return false;
            }
        }
        return true;
    }

    ////搜索的起始位置  添加逗点的数量
    void backTracking(string& s, int beginIndex, int pointNum) {
        //分割结束 3个逗点将地址分成4段
        if (pointNum == 3) {
            if (is_valid(s, beginIndex, s.size() - 1)) {
                result.push_back(s);
            }
            return;
        }
        for (int i = beginIndex; i < s.size(); i++) {
            if (is_valid(s, beginIndex, i)) {
                s.insert(s.begin() + i + 1, '.');
                backTracking(s, i + 2, pointNum + 1);
                s.erase(s.begin() + i + 1); 
            }
            else break;
        }
    }

    vector<string> restoreIpAddresses(string s) {
            backTracking(s, 0, 0);
            return result;
    }
};