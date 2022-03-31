class Solution {
public:
    string removeDuplicates(string S) {
            stack<char> st;
            for (char s : S) {
                if (st.empty() || s != st.top()) {
                    st.push(s);
                }
                else st.pop();
            }
            string result = "";
            while (!st.empty()) {
                result += st.top();
                st.pop();
            }
            reverse(result.begin(), result.end());
            return result;
    }
};


// stack<char> st;    //����ɾ����ջ
//             char stOldTop = s[0];
//             bool flag = true;
//             //��Ԫ��ѹ��ջ
//             for (int i = 0; i < s.size(); i++) {
//                 st.push(s[i]);
//                 if (stOldTop == st.top() && i > 0 && st.size() > 1) {
//                     st.pop();
//                     st.pop();
//                     flag = false;
//                 }
//                 if (flag && i > 1 && s[i] == s[i - 1] && st.size() > 1 && s[i] != s[i - 2]) {
//                 st.pop();
//                 st.pop();
//                 }
//                 if (!st.empty())    stOldTop = st.top();    //��¼�ϵ�ջ��Ԫ��
//                 flag = true;
//             }
//             stack<char> stOut;
//             while (!st.empty()) {
//                 stOut.push(st.top());
//                 st.pop();
//             }
//             s.resize(stOut.size());
//             for (int i = 0; i < s.size(); i++) {
//                 s[i] = stOut.top();
//                 stOut.pop();
//             }
//             return s;