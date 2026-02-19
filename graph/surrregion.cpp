// You are given a 2D board containing:
// 'X' and 'O'
// Your task is:
// Convert all 'O' that are completely surrounded by 'X' into 'X'.
// What does "surrounded" mean?
// An 'O' is surrounded if:
// It is surrounded from all 4 sides (up, down, left, right) by 'X'
// AND it is NOT connected to boundary
/*
Logic:
1. Boundary ke saare 'O' safe hote hain, unhe DFS se '#' mark kar dete hain
2. Jo 'O' mark nahi hue wo surrounded hain, unhe 'X' bana dete hain
3. Jo '#' mark kiye the unhe wapas 'O' bana dete hain

Time Complexity: O(n*m)
Space Complexity: O(n*m) (DFS stack)
*/

class Solution {
public:
       int n,m;
           // DFS function jo boundary se connected 'O' ko mark karega as safe
       void dfs(vector<vector<char>>& board,int i,int j)
       {
         // agar out of bounds hai ya 'O' nahi hai to return
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]!='0')
        {
            return;
        }
            // isko '#' mark kar dete hain taaki pata chale ye safe hai
          board[i][j]='#';
                 // 4 directions me DFS call karte hain (up, down, left, right)
          dfs(board,i+1,j);
          dfs(board,i-1,j);
          dfs(board,i,j+1);
          dfs(board,i,j-1);
       }
    
    void solve(vector<vector<char>>& board) {
        // rows count
     n=board.size();

     // edge case agar empty board hai
     if(n==0) return;

     // columns count
     m=board[0].size();

     // Step 1: boundary ke saare 'O' find karo aur DFS chalao
     for(int i=0;i<n;i++)
     {
          // left boundary check
        if(board[i][0]=='0')
        {
            dfs(board,i,0);
        }
        // right boundary check
        if(board[i][m-1]=='0')
        {
            dfs(board,i,m-1);
        }
     }

// top aur bottom boundary check
     for(int j=0;j<m;j++)
     {
         // top boundary
        if(board[0][j]=='0')
        {
            dfs(board,0,j);
        }
        // bottom boundary
        if(board[n-1][j]=='0')
        {
            dfs(board,n-1,j);
        }
     } 


      // Step 2: ab pura board traverse karo
     for(int i=0;i<n;i++)
     {
        for(int j=0;j<m;j++)
        {
            // agar 'O' hai matlab ye surrounded hai → isko 'X' bana do
            if(board[i][j]=='0')
            {
                board[i][j]='X';
            }
            else if(board[i][j]=='#')
            {
                 // agar '#' hai matlab safe hai → isko wapas 'O' bana do
                board[i][j]='0';
            }
        }
     }   
    }
};