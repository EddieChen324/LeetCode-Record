class Solution {
public:
    class MyQueue {
    public:
        deque<int> que;    //保证最大值永远在最前面 单调递减的队列
        ////如果要滑动的值已经弹出，就什么都不做，否则，将它弹出
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
                for (int i = 0; i < k; i++) {    //先将前k个元素放入栈中
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