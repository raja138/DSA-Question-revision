//Tumhe ek matrix diya hai
//Example:
// 1 3 1
// 1 5 1
// 4 2 1

//Tumhari starting position hai
//Top Left → 1
//Tumhari destination hai
//Bottom Right → 1

//Tum jab bhi kisi cell pe jaoge, uska number tumhare sum me add hoga
//Example path:
//1 → 3 → 1 → 1 → 1=
//Sum:
//= 7

//Bahut saare paths possible hain

// Example:
// Path 1:
// 1 → 3 → 1 → 1 → 1
// sum = 7
// Path 2:
// 1 → 1 → 5 → 1 → 1
// sum = 9
// Path 3:
// 1 → 1 → 4 → 2 → 1
// sum = 9
// Tumhara goal kya hai
// Sab paths me se:
// minimum sum wala path find karna hai

//logic bnane k liye
// At each cell, we take minimum of top and left path sum and add current cell value.

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();//row niklega
        int n=grid[0].size();//column niklega
        vector<int>dp(n,0);//ways of traversing
        dp[0]=grid[0][0];//Starting point hai:
//(0,0)
//Waha pahunchne ka minimum sum kya hoga?
//Sirf us cell ki value:
//grid[0][0]
//Kyuki tum wahi se start kar rahe ho.


//note first row me tm srf left se aa skte ho is liye
//pehli row ka loop chala k nikal liye
//first row me ek hi path hai 
        for(int j=1;j<n;j++)
        {
            dp[j]=dp[j-1]+grid[0][j];
        }



            for(int i=1;i<m;i++)
            {
                dp[0]+=grid[i][0];//ye kya kr rha hai ab tm first column me kaise aa skte ho srf ek path hai jo hai up se
                //Sabse pehle logic samjho
//Tum first column me ho:




                for(int j=1;j<n;j++)
                {
                    //ab bhai isme ye hai ki
                    //hm current me jodte hi the 
                    //to grid[i][j] me min jod rhe 
                    //
                    //sbse pehle ye smjho ki
                    //dp[j] me hi row column ka minimum path rhega
//isliye dp[j]= dp[i][j](cuurent jha khade ho)
//current pe kha se aa skte ho up se ya left se
//min(dp[j],dp[j-1])
                    dp[j]=grid[i][j]+min(dp[j],dp[j-1]);
                }
            }
            return dp[n-1];
            //return kr do jaise krte hai
        
    }
};