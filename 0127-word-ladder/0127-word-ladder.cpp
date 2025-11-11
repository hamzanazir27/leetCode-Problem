class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> wordset(wordList.begin(), wordList.end());

        if (wordset.find(endWord) == wordset.end()) {
            return 0;
        }

        queue<string> q;

        unordered_set<string> visited;

        q.push(beginWord);
        visited.insert(beginWord);
        int level=1;
        while (!q.empty()) {
        int size = q.size();

        // check all words at this level
         for(int i=0;i<size;i++)
         {
            string currentWord=q.front();
            q.pop();
             
            // all alhpabets
            for(int j=0;j<currentWord.size();j++)
            {
             char orignal =currentWord[j];
            
              for(char chr='a';chr<='z';chr++)
              {
              currentWord[j]=chr;
              //word found
               if(currentWord==endWord)
               {
                       return level + 1;
;
               }

              //word exist and not visited then in clude 
              if(wordset.find(currentWord) !=wordset.end() &&
                 visited.find(currentWord) ==visited.end()
              )
              {
                q.push(currentWord);
                visited.insert(currentWord);

              }    
                

              }// for innner and inner loop
              
            
            currentWord[j] = orignal;
            }//for loop genrate all possilbe combiniations



            

         }// for loop





           level++;


        } // while


        return 0;
    }
};