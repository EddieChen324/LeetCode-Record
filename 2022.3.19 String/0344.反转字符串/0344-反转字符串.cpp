class Solution {
public:
    void reverseString(vector<char>& s) {
            ////ͷָ���βָ��һ�߽�����һ���ƶ�
            for (int i = 0, j = s.size() - 1; i < s.size()/2; i++, j--) {
                swap(s[i], s[j]);
            }
    }
};



////ע��i ���ܵ���s.size() / 2