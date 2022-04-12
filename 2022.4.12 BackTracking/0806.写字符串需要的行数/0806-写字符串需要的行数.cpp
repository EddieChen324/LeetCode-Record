class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
                int countRow = 0;     //ռ�õ�����
                int lastCount = 0;    //���һ��ռ�õĵ�λ
                for (char word : s) {
                    if (lastCount + widths[word - 'a'] > 100) {
                        lastCount = widths[word - 'a'];
                        countRow++;
                    }
                    else lastCount += widths[word - 'a'];
                }
                if (lastCount != 0) countRow++;
                return {countRow, lastCount};
    }
};