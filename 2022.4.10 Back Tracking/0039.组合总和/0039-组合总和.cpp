class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;
    void backTracking(vector<int>& candidates, int sum, int beginIndex) {
        if (sum < 0) return;
        if (sum == 0) {
            result.push_back(path);
        }

        for (int i = beginIndex; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            backTracking(candidates, sum - candidates[i], i);    //����i+1�ظ���ȡ��ǰ����
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
                backTracking(candidates, target, 0);
                return result;
    }
};

////��ͬһ�����ϵĲ�ͬ��� startIndex ����������ʼ����  ��ͬ���ϵĲ�ͬ��� startIndex����������һ������