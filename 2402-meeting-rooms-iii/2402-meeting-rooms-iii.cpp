class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<int> count(n, 0);
        priority_queue<int, vector<int>, greater<int>> available;
        for (int i = 0; i < n; i++)
            available.push(i);
// priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> busy;
priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> busy;


        for (int i = 0; i < meetings.size(); i++) {
            int start = meetings[i][0], end = meetings[i][1];

            while (!busy.empty() && busy.top().first <= start) {
                available.push(busy.top().second);
                busy.pop();
            }
            if (!available.empty()) {
                int availableRoom = available.top();
                available.pop();
                busy.push({end, availableRoom});
                count[availableRoom]++;

            } else {
                auto [endBusy, room] = busy.top();
                busy.pop();
                long long  duration = end - start;
                long long  endlatest = duration + endBusy;
                busy.push({endlatest, room});
                 count[room]++;
            } // else

        } // for
       int result=0;
for (int i = 0; i < count.size(); i++)
{
    if(count[i]>count[result])
    result=i;
}
 return result;


    } // func
};