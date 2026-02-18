// Tumne MS Paint use kiya hoga.
// Agar tum kisi area pe paint bucket tool se click karte ho, to pura connected area same color se fill ho jata hai.
// Ye exactly wahi question hai.
// Tumhe kya diya hai
// Ek 2D grid diya hai:
// image = [
//  [1,1,1],
//  [1,1,0],
//  [1,0,1]
// ]
// Aur diya hai:
// sr = 1
// sc = 1
// newColor = 2
// Matlab start cell = (1,1)
// Rule kya hai
// Start cell ka color dekho:
// image[1][1] = 1
// Ab jo bhi cells connected hain aur same color ke hain, unko newColor se replace karo.
// Connected means:
// up, down, left, right
// Diagonal allowed nahi hai.


/*
Flood Fill:
Starting cell (sr, sc) se connected sab cells jinka color same hai,
unhe newColor se replace karna hai.
Connection allowed only in 4 directions.
This is a DFS/BFS on grid problem.
*/

// Pattern recognition (IMPORTANT)
// Jab bhi question bole:
// fill
// replace
// connected cells
// same color
// 👉 Think DFS or BFS on grid




class Solution {
public:
// Ab starting cell se traversal karna hai
// Kaunsa traversal use kar sakte hain?
// DFS  ✅
// BFS  ✅
// Most common → DFS

//Neighbours kaise check karenge
// 4 directions:
// up
// down
// left
// right
// Using dx, dy:
// dx = {-1,1,0,0}
// dy = {0,0,-1,1}
    void dfs( int x,int y,vector<vector<int>>&image,
        vector<vector<int>>& result,
        int newColor,
        int oldColor,int n,int m)
    {
        result[x][y]=newColor;
        //up down left right traverse krne k liye
        vector<int>dx={-1,1,0,0};
        vector<int>dy={0,0,-1,1};
        for(int d=0;d<4;d++)
        {
            //check neighbours
            int nx=x+dx[d];
            int ny=y+dy[d];

            //dfs call on valid same neigbours

            if(nx>=0 && ny>=0 && nx<n &&ny<m
             && image[nx][ny]==oldColor && result[nx][ny]!=newColor)//DFS tabhi call hoga agar: valid cell ho AND same oldColor ho
             {
                dfs(nx,ny,image,result,newColor,oldColor,n,m);
             }
        }
    }
//     Step 1: oldColor store karo
// Step 2: DFS call karo starting cell se
// Step 3: DFS me:
//         current cell ko newColor karo
// Step 4: neighbours check karo
// Step 5: agar neighbour same oldColor hai
//         DFS call karo

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n=image.size();//number of rows
        int m=image[0].size();//number of columns

        //// original image ki copy bana rahe hain
// kyuki hum result matrix me newColor fill karenge
// original image ko reference ke liye use karenge
// result matrix hi final answer hoga
        vector<vector<int>>result=image;

        
        // starting cell ka original color store kar rahe hain
// sirf un cells ko change karna hai
// jinka color oldColor ke equal ho
// Example:
// sr=1, sc=1
// image[1][1] = 1
// oldColor = 1
        int oldColor=image[sr][sc];
        dfs(sr,sc,image,result,newColor,oldColor,n,m);
        return result;
    }
};

//isko likh lena lengthy hai to revise krte time likh lena