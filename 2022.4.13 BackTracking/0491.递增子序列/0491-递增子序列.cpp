class Solution {
public:
    ////��Ϊ������������ ���Բ��ܶ�ԭ��������
    vector<vector<int>> result;
    vector<int> path;
    void backTracking(vector<int>& nums, int startIndex) {
        if (path.size() > 1) {
            result.push_back(path);
        }

        unordered_set<int> used;    //��Ա����Ԫ�� ȥ��
        for (int i = startIndex; i < nums.size(); i++) {
            if (!path.empty() && nums[i] < path.back() 
            || used.find(nums[i]) != used.end()) {
                    continue;
            }
            used.insert(nums[i]);    //�µ�һ��used�����
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