class Solution {
public:
    int get_square(int n) {
        int sum = 0;    //一个数字每个位置的平方和
        while (n) {
            int tmp = n % 10;
            sum += tmp * tmp;
            n = n / 10;    //更新数字
        }
        return sum;
    }
    bool isHappy(int n) {
        ////储存平方结果的集合，如果有重复说明陷入死循环
        unordered_set<int> result;
        while (1) {
            int sum = get_square(n);
            if (sum == 1) {
                return true;
            }
            if (result.find(sum) != result.end()) {
                return false;
            }
            else {
                result.insert(sum);
            }
            n = sum;
        }
    }
};