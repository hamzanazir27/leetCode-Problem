class Solution {
public:
    string minWindow(string s, string t) {
       if (t.size() > s.size()) return "";
       unordered_map<char,int> t_window;
       unordered_map<char,int> s_window;
       for (char i:t) 
           t_window[i]++;
       

       int required=t_window.size();
       int left=0;
      int minLen=INT_MAX;
      int startStr=0;
       int need=0;
       for(int right=0;right<s.size();right++)
       {
           s_window[s[right]]++;
        //    str.push_back(s[right]);
           if(t_window.count(s[right]) && s_window[s[right]] ==t_window[s[right]])
             need++;
           


           while(need==required)
           {
              if(right-left+1 <minLen)
              {
                minLen=right-left+1;
                startStr=left;
              }
           
            s_window[s[left]]--;

            if(t_window.count(s[left]) && s_window[s[left]] < t_window[s[left]])
                   need--;
            left++;

           }
             

       }
      

     return minLen == INT_MAX ? "" :s.substr(startStr,minLen);


    }
};