class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
            int left = 0;
            int right = letters.size() - 1;
            while (left <= right) {
                int middle = left + (right - left) / 2;
                if (letters[middle] > target) right = middle - 1;
                else left = middle + 1;
            }
            return letters[left % letters.size()];
    }
};