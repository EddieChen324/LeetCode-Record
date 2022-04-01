class Solution {
public:
    static bool cmp(const pair<int, int>& x, const pair<int, int>& y) {    
    return x.second > y.second;
    }     
    vector<int> topKFrequent(vector<int>& nums, int k) {
                unordered_map<int, int> result;    //�������Ԫ�غ�����ִ���
                sort(nums.begin(), nums.end());
                stack<int> st;
                for (int i = 0; i < nums.size(); i++) {
                    if (st.empty() || nums[i] == st.top())    st.push(nums[i]);
                    ///�м�Ԫ�ز��������ͬ
                    if (nums[i] != st.top()) {
                        result.insert(pair<int, int>(st.top(), st.size()));
                        while (!st.empty()) {
                            st.pop();    //��յ�ǰջ
                        }
                        st.push(nums[i]);    //�����һ����ͬ��Ԫ��
                    }
                    ////���һ��Ԫ�ص����Ҫ���⿼��
                    if (i == nums.size() - 1) result.insert(pair<int, int>(st.top(), st.size()));
                }
                //��map��Ԫ�ش���vector����value������
                vector<pair<int, int>> vec(result.begin(), result.end());
                sort(vec.begin(), vec.end(), cmp);
                vector<int> final_result(k, 0);
                for (int i = 0; i < k; i++) {
                    final_result[i] = vec[i].first;
                }
                return final_result;
    }
};