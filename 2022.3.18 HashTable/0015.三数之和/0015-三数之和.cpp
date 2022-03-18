class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> result;
            sort(nums.begin(), nums.end());
            ////forѭ�������黬��
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] > 0) {
                    return result;
                }
                ////ȥ���ظ�����������������Ԫ��ĵ�һ��Ԫ���ظ���
                if (i > 0 && nums[i] == nums[i-1]) {
                    continue;
                }
                int left = i + 1;
                int right = nums.size() - 1;
                while (left < right) {
                    if (nums[i] + nums[left] + nums[right] > 0) {
                        right--;
                    }
                    ////������else if,��Ϊright--�Ѿ��ı���sum����ֵ
                    else if (nums[i] + nums[left] + nums[right] < 0) {
                        left++;
                    }
                    else   {
                        result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                        while (left < right && nums[right] == nums[right-1]) 
                        {right--;}
                        while (left < right && nums[left] == nums[left+1]) 
                        {left++;}
                        ////ָ����ƶ�һλ
                        left++;
                        right--;
                    }
                }
            }
            return result;
    }
};

////ifע������
////if if Ϊ�����ģ�ִ��ÿһ��if������
////if elif elif.... elseΪ�����ģ�ִֻ��һ��