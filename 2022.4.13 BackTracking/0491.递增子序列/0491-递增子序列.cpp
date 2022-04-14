class Solution {
public:
    ////因为求自增子序列 所以不能对原序列排序
    vector<vector<int>> result;
    vector<int> path;
    void backTracking(vector<int>& nums, int startIndex) {
        if (path.size() > 1) {
            result.push_back(path);
        }

        unordered_set<int> used;    //针对本层的元素 去重
        for (int i = startIndex; i < nums.size(); i++) {
            if (!path.empty() && nums[i] < path.back() 
            || used.find(nums[i]) != used.end()) {
                    continue;
            }
            used.insert(nums[i]);    //新的一层used会清空
            path.push_back(nums[i]);
            backTracking(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
                backTracking(nums, 0);
                return result;
    }
};