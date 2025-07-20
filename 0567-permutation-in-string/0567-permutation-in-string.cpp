class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
    unordered_map<char, int> s1Window;

    unordered_map<char, int> s2Window;

        if (s1.size()> s2.size()) 
           return false;
       int left=0;
       for(int i=0;i<s1.size(); i++ )
       {
          s1Window[s1[i]]++;
       }
         


       for(int right=0; right<s2.size();right++)
       {

          s2Window[s2[right]]++;
         
        //  if(s1Window==s2Window)
        //  {
        //     return true;
        //  }





        if( right-left+1  > s1.size())
        {
         s2Window[s2[left]]--;
        if (s2Window[s2[left]] == 0)
           s2Window.erase(s2[left]);
         left++;


        }


       



       if (right - left + 1 == s1.size() && s1Window == s2Window)
         return true;

       }
        

    return false;
    }


};