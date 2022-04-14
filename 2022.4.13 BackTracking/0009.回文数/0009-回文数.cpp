class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
       string s = to_string(x);
       for (int i = 0, j = s.size() - 1; i < s.size(); i++, j--) {
           if (s[i] != s[j]) return false;
       }
       return true;     
    }
};