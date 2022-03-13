class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;    //������ָ��
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {     //���ÿ�ָ��
            if (val != nums[fastIndex]) {
                nums[slowIndex++] = nums[fastIndex];   
                //���û�ҵ����ҵ�Ԫ�أ������ָ��ͬʱ�ƶ������ҵ�����ֻ�п�ָ�붯������val�����ֵ����ǰ���ֵ
            }
        }
        return slowIndex;
    }
};