class Solution {
public:
    void reverse(string& s, int begin, int end) {
        for (int i = begin, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }
    string reverseLeftWords(string s, int n) {
            reverse(s, 0, n - 1);    //��תǰn��Ԫ��
            reverse(s, n, s.size() - 1);    //��ת�����Ԫ��
            reverse(s, 0, s.size() - 1);
            return s;
    }
};