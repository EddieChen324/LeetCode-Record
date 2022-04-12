class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
                int countRow = 0;     //占用的行数
                int lastCount = 0;    //最后一行占用的单位
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