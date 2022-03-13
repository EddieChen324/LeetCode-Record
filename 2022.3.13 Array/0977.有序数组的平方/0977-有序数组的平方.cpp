class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size(), 0);    //创建新数组
        int i,j;
        int k = result.size() - 1;
        for (i = 0, j = result.size() - 1; i <= j;) {
            //因为是非递减顺序，所以仅比较两端的数据就可以了，然后移动两端的指针
            if (nums[i] * nums[i] < nums[j] * nums[j]) {    
                result[k--] = nums[j] * nums[j];
                j--;
            }
            else {
                result[k--] = nums[i] * nums[i];
                i++;
            }
        }
        return result;
    }
};