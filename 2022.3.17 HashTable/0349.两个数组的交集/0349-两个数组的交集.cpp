class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
            unordered_set<int> result;    //��������Ľ���
            unordered_set<int> nums1_set(nums1.begin(), nums1.end());    //��һ�������ΨһԪ��
            //����nums2������Ԫ��
            for (int num : nums2) {
            //�ڵ�һ������ļ�����Ҳ�ҵ��ڶ��������Ԫ��
            if (nums1_set.find(num) != nums1_set.end()) {
                result.insert(num);
            }
            }
            return vector<int>(result.begin(), result.end());
    }
};


//����ע��ĵط�
//unorder_set��ʼ�� unordered_set<type> name(xxx.begin(), xxx.end())
//for loop�ǵü�ѭ���Ķ���������
//for(int num : num2)