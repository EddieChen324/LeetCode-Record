class Solution {
public:
    void revolve(string& s) {
        int slowIndex = 0;
        int fastIndex = 0;
        char begin = s[0];
        for (; fastIndex < s.size(); fastIndex++) {
            if (fastIndex == 0) continue;
            else s[slowIndex++] = s[fastIndex];
        }
        s[s.size() - 1] = begin;
    }
    bool rotateString(string s, string goal) {
            string begin = s;
            while(s != goal) {
                revolve(s);
                if (s == begin) return false;
                if (s == goal) return true;
            }
            return false;
    }
};