// Multi-source BFS use karna hai
// Sab rotten oranges ko queue me daalo initially
// Har BFS level = 1 minute
// Fresh orange milte hi rotten banao aur queue me daalo
// Agar end me fresh > 0 → return -1
/*
ROTTING ORANGES
0 = empty
1 = fresh orange
2 = rotten orange
Har minute rotten orange apne 4-direction me fresh oranges ko rotten bana deta hai.
Goal:
Sab oranges rotten hone me minimum time find karna hai.
Key idea:
Ye multi-source BFS hai kyunki multiple rotten oranges ek saath infection spread karte hain.
Each BFS level = 1 minute
*/

//meri language me
//Socho tumhare paas ek fruit box hai jisme oranges rakhe hain.
//3 types ke cells ho sakte hain:
//0 = empty (kuch nahi hai)
//1 = fresh orange 🍊
//2 = rotten orange 🤢
//Rule:
// Har minute, rotten orange apne 4 neighbours (up, down, left, right) me fresh oranges ko bhi rotten bana deta hai.

//condition--
//Agar koi fresh orange isolated hai, jaise:
//2 0 1
//Yaha fresh orange kabhi rotten nahi banega.
//Answer = -1

// Step 1: queue banao
// Step 2: sab rotten oranges queue me daalo
// Step 3: fresh oranges count karo
// Step 4: BFS chalao
//         har level = 1 minute
// Step 5: jab fresh orange mile
//         fresh--
//         rotten banao
//         queue me daalo
// Step 6: end me check karo
//         agar fresh > 0 → return -1
//         else return time

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();//number of rows in grid
        int m=grid[0].size();//number of columns in grid
//         grid =
// [
//  [2,1,1],
//  [1,1,0],
//  [0,1,1]
// ]

// n = 3
// m = 3

        queue<pair<int,int>>q;

        // Ye BFS queue hai
// isme hum rotten oranges ke positions store karenge
// pair<int,int> represent karta hai:
// first  = row index
// second = column index
// Example:
// q.push({0,0}) means rotten orange at (0,0)
        int fresh=0;
        // Ye fresh oranges count karega

// hume ye track karna hai ki kitne fresh oranges bache hain

// agar end me fresh > 0
// matlab sab rotten nahi ho paye
// answer = -1
        int time=0;
        /// Ye total minutes count karega
// har BFS level = 1 minute
// jab infection next level tak spread karega
// tab time increase hoga
// Example:
// Minute 0 → initial state
// Minute 1 → first spread
// Minute 2 → second spread


//Pura grid scan kar raha hai aur 2 kaam kar raha hai:
// 1. Rotten oranges → queue me daal raha hai
// 2. Fresh oranges → count kar raha hai
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                // // agar current cell me rotten orange hai
                if(grid[i][j]==2)
                {
                    // // uska position queue me daal do
            // ye BFS ke starting points honge (multi-source BFS)
                    q.push({i,j});
                }.    //// agar fresh orange hai
                else if(grid[i][j]==1)
                {
                 

                     // fresh oranges count karo
                    fresh++;
                }
            }
        }

//// dx, dy arrays use ho rahe hain 4-direction movement ke liye
// (x-1,y) → up
// (x+1,y) → down
// (x,y-1) → left
// (x,y+1) → right
// BFS me neighbours explore karne ke liye use hota hai
        vector<int>dx={-1,1,0,0};
        vector<int>dy={0,0,-1,1};


//// jab tak queue empty nahi hai aur fresh oranges bache hain
// tab tak BFS chalayenge

// queue empty → infection spread nahi ho sakta
// fresh == 0 → sab oranges rotten ho gaye
        while(!q.empty() && fresh>0)
        {
           int size=q.size(); // ye current level me kitne rotten oranges hain
// IMPORTANT:
// ek level = 1 minute
// isliye hume exactly itne elements process karne hain

            
            for(int i=0;i<size;i++)
            {
                auto it=q.front();// queue se ek rotten orange nikala
// ye infection spread karega
                q.pop();
                
                //Position extract karna
                //// current rotten orange ka position
                int x=it.first;
                int y=it.second;

                for(int d=0;d<4;d++)
                {
                    //direction check karna
                    // neighbours check kar rahe hain
                   // up, down, left, right
                    int nx=x+dx[d];
                    int ny=y+dy[d];

//// boundary check
// aur check ki neighbour fresh orange hai ya nahi
                    if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==1)
                    {
                        grid[nx][ny]=2;
                        fresh--;
                        q.push({nx,ny});
                        // fresh orange ko rotten bana diya
// fresh count kam kar diya
// newly rotten orange ko queue me daal diya
// taaki next minute ye bhi infection spread kare
                    }
                }
            }
            // ek BFS level complete hua
// iska matlab 1 minute pass ho gaya
            time++;
        }

        if(fresh>0)
        {
            return -1;//If fresh oranges remain after BFS, it means some oranges were unreachable, so return -1.
        }
        //otherwise written time 
        return time;

    }
};