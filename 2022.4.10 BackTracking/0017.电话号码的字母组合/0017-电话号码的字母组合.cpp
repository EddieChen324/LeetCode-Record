class Solution {
public:
    ////����һ�����ֺ���ĸ��ӳ��
    const string letterMap[10] = {
        "",    //0
        "",    //1
        "abc", //2
        "def", //3
        "ghi", //4
        "jkl", //5
        "mno", //6
        "pqrs", //7
        "tuv", //8
        "wxyz", //9
    };
    vector<string> result;
    string str;    //ÿһ��string
    void backTracking(string digits, int beginIndex) {
        if (str.size() == digits.size()) {
            result.push_back(str);
            return;
        }
        // for (int i = beginIndex; i < digits.size(); i++) {
            string tmp = "";
            tmp += letterMap[(int)(digits[beginIndex] - '0')];
            for (int j = 0; j < tmp.size(); j++) {
                str += tmp[j];
                backTracking(digits, beginIndex + 1);    //����дi + 1��ҪдbeginIndex��������
                str.resize(str.size() - 1);
            }
        // }
    }
    vector<string> letterCombinations(string digits) {
            if (digits.size() == 0) return result;
            backTracking(digits, 0);
            return result;
    }
};