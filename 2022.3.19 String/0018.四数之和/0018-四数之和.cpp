class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
            vector<vector<int>> result;
            ////���ȶ������������
            sort(nums.begin(), nums.end());
            ////�趨����ָ��ȷ��ǰ������
            for (int i = 0; i < nums.size(); i++) {
                // if (nums[i] > target) {
                //     return result;
                // }
                if (i > 0 && nums[i] == nums[i - 1]) {
                    continue;
                }
                for (int j = i + 1; j < nums.size(); j++) {
                    if (j > i + 1 && nums[j] == nums[j - 1]) {
                        continue;
                    }
                    ////�趨����ָ��
                    int left = j + 1;
                    int right = nums.size() - 1;
                    while (left < right) {
                        if (nums[i] + nums[j]  > target - (nums[left] + nums[right])) {
                            right--;
                        }
                        else if (nums[i] + nums[j]  < target - (nums[left] + nums[right])) {
                            left++;
                        }
                        else {
                            result.push_back({nums[i], nums[j], nums[left], nums[right]});
                            ////�ж�ȥ������
                            while (left < right && nums[left] == nums[left + 1]) 
                                left++;
                            while (left < right && nums[right] == nums[right - 1])
                                right--;
                            ////
                            left++;
                            right--;
                        }
                    }
                }
            }
            return result;
    }
};



////��ע
//nums[k] + nums[i] + nums[left] + nums[right] > target �����