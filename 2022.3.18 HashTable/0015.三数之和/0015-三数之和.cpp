class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> result;
            sort(nums.begin(), nums.end());
            ////for循环在数组滑动
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] > 0) {
                    return result;
                }
                ////去掉重复的情况，这种情况三元组的第一个元素重复了
                if (i > 0 && nums[i] == nums[i-1]) {
                    continue;
                }
                int left = i + 1;
                int right = nums.size() - 1;
                while (left < right) {
                    if (nums[i] + nums[left] + nums[right] > 0) {
                        right--;
                    }
                    ////必须用else if,因为right--已经改变了sum的数值
                    else if (nums[i] + nums[left] + nums[right] < 0) {
                        left++;
                    }
                    else   {
                        result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                        while (left < right && nums[right] == nums[right-1]) 
                        {right--;}
                        while (left < right && nums[left] == nums[left+1]) 
                        {left++;}
                        ////指针各移动一位
                        left++;
                        right--;
                    }
                }
            }
            return result;
    }
};

////if注意事项
////if if 为独立的，执行每一个if里的语句
////if elif elif.... else为关联的，只执行一次