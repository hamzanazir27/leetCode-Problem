class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
       int totalGas=0;
       int currentGas=0;
       int startIndex=0;
       for(int i=0;i<gas.size();i++)
       {
        totalGas += gas[i]-cost[i];
        currentGas +=gas[i]-cost[i];
        if(currentGas<0)
        {
            startIndex=i+1;
            currentGas=0;
        }
       } 
           return totalGas>=0?startIndex:-1;

    }

};