class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int sec = 0;
        int i = 0;

        while (tickets[k] != 0) {
            if (tickets[i] > 0) {   // sirf unhi logon ko ticket do jinke pass bachi ho
                tickets[i]--;
                sec++;
            }
            i++;
            if (i == tickets.size()) i = 0; // full round complete ho gaya
        }
        return sec;
    }
};
