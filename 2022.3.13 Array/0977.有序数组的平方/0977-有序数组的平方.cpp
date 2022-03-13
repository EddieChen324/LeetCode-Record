class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size(), 0);    //����������
        int i,j;
        int k = result.size() - 1;
        for (i = 0, j = result.size() - 1; i <= j;) {
            //��Ϊ�Ƿǵݼ�˳�����Խ��Ƚ����˵����ݾͿ����ˣ�Ȼ���ƶ����˵�ָ��
            if (nums[i] * nums[i] < nums[j] * nums[j]) {    
                result[k--] = nums[j] * nums[j];
                j--;
            }
            else {
                result[k--] = nums[i] * nums[i];
                i++;
            }
        }
        return result;
    }
};