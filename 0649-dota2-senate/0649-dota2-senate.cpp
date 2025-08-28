class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> dire, radiant;
        for (int i = 0; i < senate.size(); i++) {
            if (senate[i] == 'D') {
                dire.push(i);
            } else {
                radiant.push(i);
            }
        }

        while(!dire.empty() && !radiant.empty())
        {
           int dir=dire.front();
           int rd= radiant.front();
           radiant.pop();
           dire.pop();
            // [DR]

          if(dir<rd)
          {
            dire.push(dir+senate.size());
          }
          else
          {
           radiant.push(rd+senate.size());
          }




        }

        return radiant.empty() ? "Dire" :"Radiant";

    }
};