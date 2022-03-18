class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> result;
            for (int i = 0; i < nums.size(); i++) {
                ////在map里查找是否有元素符合与nums[i]相加为target
                auto iter = result.find(target - nums[i]);
                ////如果找到，就返回他们的下标
                if (iter != result.end()) {
                    return {iter->second, i};
                }
                else {
                    result.insert(pair<int, int>(nums[i], i));
                }
            }
            return {};
    }
};

////map注意事项
////map.insert(pair<int, int>(nums[i], i))