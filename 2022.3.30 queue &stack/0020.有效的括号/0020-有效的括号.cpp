class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(')');
            else if (s[i] == '{') st.push('}');
            else if (s[i] == '[') st.push(']');
            // ����������������ַ���ƥ��Ĺ����У�ջ�Ѿ�Ϊ���ˣ�û��ƥ����ַ��ˣ�˵��������û���ҵ���Ӧ�������� return false
            // �ڶ�������������ַ���ƥ��Ĺ����У�����ջ��û������Ҫƥ����ַ�������return false
            else if (st.empty() || st.top() != s[i]) return false;
            else st.pop(); // st.top() �� s[i]��ȣ�ջ����Ԫ��
        }
        // ��һ���������ʱ�����Ѿ����������ַ���������ջ��Ϊ�գ�˵������Ӧ��������û����������ƥ�䣬����return false�������return true
        return st.empty();
    }
};