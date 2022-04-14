class Solution {
public:
    //��������  ����������������
    unordered_map<string, map<string, int>> targets;
    bool backTracking(int ticketNum, vector<string>& result) {
        if (result.size() == ticketNum + 1) {
        return true;
    }
    for (pair<const string, int>& target : targets[result[result.size() - 1]]) {
        if (target.second > 0 ) { // ��¼��������Ƿ�ɹ���
            result.push_back(target.first);
            target.second--;
            if (backTracking(ticketNum, result)) return true;
            result.pop_back();
            target.second++;
        }
    }
    return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
            targets.clear();
        vector<string> result;
        for (const vector<string>& vec : tickets) {
            targets[vec[0]][vec[1]]++; // ��¼ӳ���ϵ
        }
        result.push_back("JFK"); // ��ʼ����
        backTracking(tickets.size(), result);
        return result;
    }
};