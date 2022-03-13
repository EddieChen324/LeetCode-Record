class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT32_MAX;    //���ս��
        int sublength = 0;    //ÿ�λ������ڵĴ�С�����ں�result�ȽϿ��Ƿ���Ҫ����
        int begin = 0;    //���ڵ���ʼλ��
        int end;    //���ڵĽ���λ��
        int sum = 0;    //���ڵ�����֮��
        for (end = 0; end < nums.size(); end++) {
            sum += nums[end];  
            //���ڽ���λ��һֱ����ֱ�����ڵ���target
            while (sum >= target) {
                sublength = end - begin + 1;    //������һ�ִ��ڵĴ�С
                result = result < sublength ? result :sublength;  //�ж��Ƿ���Ҫ����
                sum -= nums[begin++];    //���ڿ�ʼλ��Ҳ��ǰ����
            }
        }
        //��resultû�б���ֵ˵��û���������������У�����0
        return result == INT32_MAX ? 0 : result;
    }
};