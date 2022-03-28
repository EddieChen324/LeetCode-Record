class Solution {
public:
    void getNext(int* next, const string& s) {
        int j = 0;
        next[0] = 0;
        for(int i = 1; i < s.size(); i++) {
            while (j > 0 && s[i] != s[j]) {
                j = next[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
    }
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        int next[needle.size()];
        getNext(next, needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); i++) {
            ////如果已经匹配了几个字符，但是接下来的没匹配上就回退
            while(j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }
            ////匹配上一个就++
            if (haystack[i] == needle[j]) {
                j++;
            }
            ////如果全部匹配则j == 模式串大小
            if (j == needle.size() ) {
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};