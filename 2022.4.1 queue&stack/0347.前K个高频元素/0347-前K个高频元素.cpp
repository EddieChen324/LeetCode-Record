class Solution {
public:
    static bool cmp(const pair<int, int>& x, const pair<int, int>& y) {    
    return x.second > y.second;
    }     
    vector<int> topKFrequent(vector<int>& nums, int k) {
                unordered_map<int, int> result;    //存放数组元素和其出现次数
                sort(nums.begin(), nums.end());
                stack<int> st;
                for (int i = 0; i < nums.size(); i++) {
                    if (st.empty() || nums[i] == st.top())    st.push(nums[i]);
                    ///中间元素插入情况不同
                    if (nums[i] != st.top()) {
                        result.insert(pair<int, int>(st.top(), st.size()));
                        while (!st.empty()) {
                            st.pop();    //清空当前栈
                        }
                        st.push(nums[i]);    //加入第一个不同的元素
                    }
                    ////最后一个元素的情况要另外考虑
                    if (i == nums.size() - 1) result.insert(pair<int, int>(st.top(), st.size()));
                }
                //把map中元素存入vector中以value来排序
                vector<pair<int, int>> vec(result.begin(), result.end());
                sort(vec.begin(), vec.end(), cmp);
                vector<int> final_result(k, 0);
                for (int i = 0; i < k; i++) {
                    final_result[i] = vec[i].first;
                }
                return final_result;
    }
};