class Solution {
public:
    int evalRPN(vector<string>& tokens) {
            stack<int> st;    
            for (int i = 0; i < tokens.size(); i++) {
                if (tokens[i] != "+" && tokens[i] != "-"  
                && tokens[i] != "*" && tokens[i] != "/") {
                    st.push(stoi(tokens[i]));    //转int再放入栈
                }
                else {
                    int num1 = st.top();
                    st.pop();
                    int num2 = st.top();
                    st.pop();
                    if (tokens[i] == "+") {int result = num2 + num1;
                    st.push(result);}
                    if (tokens[i] == "-") {int result = num2 - num1;
                    st.push(result);}
                    if (tokens[i] == "*") {int result = num2 * num1;
                    st.push(result);}
                    if (tokens[i] == "/") {int result = num2 / num1;
                    st.push(result);}
                }
            }
            int output = st.top();
            return output;
    }
};