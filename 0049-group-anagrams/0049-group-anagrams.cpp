class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> groups;
        for(auto str:strs)
        {
            //assending order bdc->abc for key 
            string key=str;
            sort(key.begin(),key.end());
            groups[key].push_back(str);
            
        }//

        vector<vector<string>> result;
        for(auto [fst,scd]:groups)
        {
            result.push_back(scd);
        }
        return result;


    }
};