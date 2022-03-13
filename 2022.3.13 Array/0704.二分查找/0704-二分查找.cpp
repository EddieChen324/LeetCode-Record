class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0; 
        int right = nums.size() - 1; //左闭右闭版本，可以取到size-1的地方
        while (left <= right){
            int middle = left + ((right - left) / 2);
            if (nums[middle] < target){
                left = middle + 1;
            }
            else if (nums[middle] > target){
                right = middle -1;
            }
            else{
                return middle;
            }
        }
        //未找到目标值
        return -1;
    }
};