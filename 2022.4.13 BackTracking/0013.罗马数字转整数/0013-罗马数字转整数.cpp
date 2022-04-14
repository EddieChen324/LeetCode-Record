class Solution {
public:
    int romanToInt(string s) {
            reverse(s.begin(), s.end());
            int count = 0;
            for (int i = 0; i < s.size(); i++) {
                if ((i > 0 && s[i] == 'I' && s[i - 1] != 'V' && s[i - 1] != 'X') || 
                i == 0 && s[i] == 'I') {
                    count += 1;
                }
                else if (i > 0 && s[i] == 'I' && (s[i - 1] == 'V' || s[i - 1] == 'X')) {
                    count -= 1;
                }
                if (i > 0 && s[i] == 'X' && s[i - 1] != 'L' && s[i - 1] != 'C' ||
                i == 0 && s[i] == 'X') {
                    count += 10;
                }
                else if (i > 0 && s[i] == 'X' && (s[i - 1] == 'L' || s[i - 1] == 'C')) {
                    count -= 10;
                }
                if (i > 0 && s[i] == 'C' && s[i - 1] != 'D' && s[i - 1] != 'M' ||
                i == 0 && s[i] == 'C') {
                    count += 100;
                }
                else if (i > 0 && s[i] == 'C' && (s[i - 1] == 'D' || s[i - 1] == 'M')) {
                    count -= 100;
                }
                if (s[i] == 'V') {
                    count += 5;
                }
                else if (s[i] == 'L') {
                    count += 50;
                }
                else if (s[i] == 'D') {
                    count +=500;
                }
                else if (s[i] == 'M') {
                    count += 1000;
                }
            }
             return count;
    }
};