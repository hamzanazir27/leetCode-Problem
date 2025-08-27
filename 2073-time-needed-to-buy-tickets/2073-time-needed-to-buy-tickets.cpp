



class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
      int result=0;
 
      for(int i=0;i<tickets.size();i++)
      {
        if(i<=k)
         result +=min(tickets[k],tickets[i]);
         else
         result +=min(tickets[k]-1,tickets[i]);

      }


      return result;
    }
};







// using queue

class Solution2 {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {

        queue<pair<int, int>> q;

        for (int i = 0; i < tickets.size(); i++) {
            q.push({i, tickets[i]});
        }

        int time = 0;

        while (!q.empty()) {
            auto [pos, remain] = q.front();
            q.pop();
            remain--;
            time++;
            if (remain > 0) {
                q.push({pos, remain});
            }
            if(pos==k&& remain ==0)
            {
                return time;
            }
        }
        return time;
    }
};

// 3
// ms
// Beats
// 20.49%
// Analyze Complexity
// Memory
// 12.68
// MB
// // Beats
// 8.00%

// class Solution {
// public:
//     int timeRequiredToBuy(vector<int>& tickets, int k) {

//     }
// };

/*
Simulation approch
------------------

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int sec = 0;
        int i = 0;

        while (tickets[k] != 0) {
            if (tickets[i] > 0) {   // sirf unhi logon ko ticket do jinke pass
bachi ho tickets[i]--; sec++;
            }
            i++;
            if (i == tickets.size()) i = 0; // full round complete ho gaya
        }
        return sec;
    }
};



Space Complexity: O(1)
Kyunki hum sirf kuch variables (sec, i) use kar rahe hain, extra space nahi le
rahe. Tickets array ko modify kar rahe hain, lekin extra memory nahi ban rahi.
Time Complexity: O(n * m)
n = tickets.size() (number of people)
m = tickets[k] (number of tickets kth person wants)
Worst case: loop har person ke liye chal sakta hai har ticket khatam hone tak →
total ≈ n * m operations



*/