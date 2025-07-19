class Solution {
public:
    int characterReplacement(string s, int k) {
      unordered_map<char,int> window;
      int result=0;
      int maxFre=0;
      int left=0;
      for(int right=0;right<s.size();right++)
      {
         window[s[right]]++;
         maxFre = max(maxFre,window[s[right]]);
         if((right-left+1)-maxFre>k )
         { 
           window[s[left]]--;
           left++;
         } 
         result=(result,right-left+1);
      
    }
    return result;
    }
};