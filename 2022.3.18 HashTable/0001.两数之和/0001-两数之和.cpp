class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> result;
            for (int i = 0; i < nums.size(); i++) {
                ////��map������Ƿ���Ԫ�ط�����nums[i]���Ϊtarget
                auto iter = result.find(target - nums[i]);
                ////����ҵ����ͷ������ǵ��±�
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

////mapע������
////map.insert(pair<int, int>(nums[i], i))