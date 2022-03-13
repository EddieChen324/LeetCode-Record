class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        // if (nums[0] > target) {
        //     return 0;
        // }
        // if (nums[right] < target) {
        //     return right + 1;
        // }
        while (left <= right) {
            int middle = left + ((right - left) / 2);    //防止溢出
            if (nums[middle] < target) {
                left = middle + 1;
            }
            if (nums[middle] > target) {
                right = middle -1;
            }
            if (nums[middle] == target) {
                return middle;
            }
            // if (nums[middle] > target && nums[middle - 1] < target) {
            //     return middle;
            // }
        }
        return right + 1;
    }
};

