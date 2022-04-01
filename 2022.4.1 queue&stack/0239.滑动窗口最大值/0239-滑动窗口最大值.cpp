class Solution {
public:
    class MyQueue {
    public:
        deque<int> que;    //��֤���ֵ��Զ����ǰ�� �����ݼ��Ķ���
        ////���Ҫ������ֵ�Ѿ���������ʲô�����������򣬽�������
        void pop(int value) {
            if (!que.empty() && value == que.front()) {
                que.pop_front();
            }
        }
        void push(int value) {
            while (!que.empty() && value > que.back()) {
                que.pop_back();
            }
            que.push_back(value);
        }
        int front () {
            return que.front();
        }
    };
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
                MyQueue que;    
                vector<int> result;
                for (int i = 0; i < k; i++) {    //�Ƚ�ǰk��Ԫ�ط���ջ��
                    que.push(nums[i]);
                }
                result.push_back(que.front());
                for (int i = k; i < nums.size(); i++) {
                    que.pop(nums[i - k]);
                    que.push(nums[i]);
                    result.push_back(que.front());
                }
                return result;
    }
};