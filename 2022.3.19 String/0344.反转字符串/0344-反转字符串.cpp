class Solution {
public:
    void reverseString(vector<char>& s) {
            ////头指针和尾指针一边交换，一边移动
            for (int i = 0, j = s.size() - 1; i < s.size()/2; i++, j--) {
                swap(s[i], s[j]);
            }
    }
};



////注意i 不能等于s.size() / 2