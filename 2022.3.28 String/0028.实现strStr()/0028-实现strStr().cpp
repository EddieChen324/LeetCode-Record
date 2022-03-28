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
            ////����Ѿ�ƥ���˼����ַ������ǽ�������ûƥ���Ͼͻ���
            while(j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }
            ////ƥ����һ����++
            if (haystack[i] == needle[j]) {
                j++;
            }
            ////���ȫ��ƥ����j == ģʽ����С
            if (j == needle.size() ) {
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};