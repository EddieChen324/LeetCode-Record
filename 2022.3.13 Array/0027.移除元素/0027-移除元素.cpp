class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;    //设置慢指针
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {     //设置快指针
            if (val != nums[fastIndex]) {
                nums[slowIndex++] = nums[fastIndex];   
                //如果没找到想找的元素，则快慢指针同时移动；若找到了则只有快指针动，并用val后面的值覆盖前面的值
            }
        }
        return slowIndex;
    }
};