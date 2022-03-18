class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
            unordered_set<int> result;    //两个数组的交集
            unordered_set<int> nums1_set(nums1.begin(), nums1.end());    //第一个数组的唯一元素
            //遍历nums2的所有元素
            for (int num : nums2) {
            //在第一个数组的集合中也找到第二个数组的元素
            if (nums1_set.find(num) != nums1_set.end()) {
                result.insert(num);
            }
            }
            return vector<int>(result.begin(), result.end());
    }
};


//代码注意的地方
//unorder_set初始化 unordered_set<type> name(xxx.begin(), xxx.end())
//for loop记得加循环的东西的类型
//for(int num : num2)