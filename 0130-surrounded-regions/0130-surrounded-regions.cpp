class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(); //row
        int n = board[0].size();//coloumn
        // Row (outer array)
// ↓row
// 0 → [ X  O  X ]
// 1 → [ O  O  X ]
// 2 → [ X  X  O ]
//       ↑  ↑  ↑
//    Col0 Col1 Col2

  for(int i=0; i<m;i++)
    {
       dfs(board,i,0,m,n);//left coloumn
       dfs(board,i,n-1,m,n);//right coloumn
    }
  for(int j=0; j<n;j++)
    {
       dfs(board,0,j,m,n);//upper row
       dfs(board,m-1,j,m,n);//bottom row 
    }



        for(int i=0; i<m;i++)
        {

        for(int j=0; j<n;j++)
        {
             if( board[i][j] =='O'  )
              {
                    board[i][j]='X';
              }
             
              if( board[i][j] =='S'  )
              {
                    board[i][j]='O';
              }

            
        }//inner loop

        }//outer loop


    }

void dfs(vector<vector<char>>& board,int i,int j, int m,int n)
{
//m size of row means outer array
//n size of coloumn inner array
//---------------------------------------

if(i<0|| i>=m ||j<0|| j>=n ||board[i][j]!='O')
return;
board[i][j]='S';
dfs(board,i+1,j,m,n);
dfs(board,i,j+1,m,n);
dfs(board,i-1,j,m,n);
dfs(board,i,j-1,m,n);

}
};