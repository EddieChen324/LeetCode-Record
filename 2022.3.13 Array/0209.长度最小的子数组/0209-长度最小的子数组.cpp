class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT32_MAX;    //最终结果
        int sublength = 0;    //每次滑动窗口的大小，用于和result比较看是否需要覆盖
        int begin = 0;    //窗口的起始位置
        int end;    //窗口的结束位置
        int sum = 0;    //窗口的数字之和
        for (end = 0; end < nums.size(); end++) {
            sum += nums[end];  
            //窗口结束位置一直滑动直到大于等于target
            while (sum >= target) {
                sublength = end - begin + 1;    //计算这一轮窗口的大小
                result = result < sublength ? result :sublength;  //判断是否需要更新
                sum -= nums[begin++];    //窗口开始位置也向前滑动
            }
        }
        //若result没有被赋值说明没有满足条件的序列，返回0
        return result == INT32_MAX ? 0 : result;
    }
};