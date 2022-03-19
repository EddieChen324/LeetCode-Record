class Solution {
public:
    string replaceSpace(string s) {
            int count = 0;
            int sOldsize = s.size();
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == ' ') {
                    count++;
                }
            }
            s.resize(s.size() + count * 2);
            int sNewsize = s.size();
            for (int i = sOldsize - 1, j = sNewsize - 1; i < j; i--, j--) {
                if (s[i] != ' ') {
                    s[j] = s[i];
                }
                else {
                    s[j] = '0';
                    s[j - 1] = '2';
                    s[j - 2] = '%';
                    j -= 2;
                }
            }
            return s;
    }
};