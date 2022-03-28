class Solution {
public:
    bool repeatedSubstringPattern(string s) {
            ////����next����
            int j = 0;    //ǰ׺ĩβ
            int* next = new int[s.size()];
            next[0] = j;
            for (int i = 1; i < s.size(); i++) {
                while (j > 0 && s[i] != s[j]) {
                    j = next[j - 1];
                }
                if (s[i] == s[j]) {
                    j++;
                }
                next[i] = j;
            }
            int subLength = s.size() - next[s.size() - 1];
            if (s.size() % subLength == 0 && subLength != s.size()) {
                return true;
            }
            else {
                return false;
            }
    }
};