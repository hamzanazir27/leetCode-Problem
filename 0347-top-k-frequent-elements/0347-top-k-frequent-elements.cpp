class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>  count;
        for(auto ele:nums)
        {
            count[ele]++;
        }

        vector<pair<int,int>> arr;
        for(auto p:count)
        {
            arr.push_back({p.second,p.first});
        }


//sort in decending oder 
        sort(arr.rbegin(),arr.rend());

        vector<int> ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(arr[i].second);

        }
        return ans;
    }
};