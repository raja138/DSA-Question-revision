//Tumhe ek 2D grid diya gaya hai:
//grid[m][n]
//Har cell me:
//0 → empty space (jaa sakte ho)
//1 → obstacle (nahi ja sakte)
// Robot Ki Position
//Start = top-left corner → grid[0][0]
//End = bottom-right corner → grid[m-1][n-1]
// Allowed Moves
//Robot sirf:
//➡️ Right
// Down
//Move kar sakta hai.
//❌ Left nahi
//❌ Up nahi
//❌ Diagonal nahi
//🎯 Tumhe Kya Find Karna Hai?
//Total kitne unique paths hain jisse robot start se end tak pahunch sakta hai
//bina kisi obstacle (1) pe step kiye.
//Real Question Simplified
// Ye pooch raha hai:
// Count how many ways exist to reach bottom-right,
// while avoiding blocked cells.


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();//// number of rows
        int n=grid[0].size();// number of columns
        vector<long long>dp(n,0);//dp[j] stores number of unique ways to reach column j in the current row.
        dp[0]=(grid[0][0]==0);
        //agar obstacle hai to  grid[0][0] 1 hoga 
        //to grid[0][0]==0 false ho jayega aur dp[0] 0 ways ho jayega
        // aur agar obstacle nhi hai to dp[0] me 1 way aa jayega
        for(int i=0;i<m;i++)//iterate kroge matrix pe
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)//agar obstacle hai to way 0 ho jayega
                {
                    dp[j]=0;
                }
                else if(j>0)//initial upr cover ho gya hai line 32
                {
                    dp[j] +=dp[j-1];//current me add kr do purane se 

                }
            }

}
return dp[n-1];   //return kr do last tk puchne k liye
 }
};