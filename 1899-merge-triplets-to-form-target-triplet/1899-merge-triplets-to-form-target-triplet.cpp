class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int a=0,b=0,c=0;
        for(int indx=0;indx<triplets.size();indx++)
        {
        if(triplets[indx][0]<=target[0] && triplets[indx][1]<=target[1] && triplets[indx][2]<=target[2])
        {
            a=max(triplets[indx][0],a);
            b=max(triplets[indx][1],b);
            c=max(triplets[indx][2],c);
        }
        }

        return target[0]==a &&  target[1]==b &&  target[2]==c;
    }
};