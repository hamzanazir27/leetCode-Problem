class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
      int m=board.size();
      int n=board[0].size();
      
      for(int i=0;i<m;i++)
      {
        for(int j=0;j<n;j++)
      {
        if(backtrack( board,  word, i, j, 0))
        {
            return true ;
        }
      }
      }
      return false;
    }

   bool backtrack(vector<vector<char>>& board, string word,int row,int col,int index)
    {
        //word is found 
     if(word.size()==index)
     {
        return true;
     }
         

     //letter out of bound
     if(row<0 || row>=board.size()||col<0 || col>=board[0].size()|| word[index]!=board[row][col])
     {
        return false;
     }
   

    char temp=board[row][col];
    board[row][col]='#';
     
     bool result=backtrack( board,  word, row-1, col, index+1)  || // upword 
          backtrack( board,  word, row+1, col, index+1)  || // downword
          backtrack( board,  word, row, col-1, index+1)  || // left
          backtrack( board,  word, row, col+1, index+1) ; // right


    board[row][col]=temp;
    return result;


    }


};