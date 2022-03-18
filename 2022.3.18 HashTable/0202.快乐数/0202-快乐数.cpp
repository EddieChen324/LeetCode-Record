class Solution {
public:
    int get_square(int n) {
        int sum = 0;    //һ������ÿ��λ�õ�ƽ����
        while (n) {
            int tmp = n % 10;
            sum += tmp * tmp;
            n = n / 10;    //��������
        }
        return sum;
    }
    bool isHappy(int n) {
        ////����ƽ������ļ��ϣ�������ظ�˵��������ѭ��
        unordered_set<int> result;
        while (1) {
            int sum = get_square(n);
            if (sum == 1) {
                return true;
            }
            if (result.find(sum) != result.end()) {
                return false;
            }
            else {
                result.insert(sum);
            }
            n = sum;
        }
    }
};