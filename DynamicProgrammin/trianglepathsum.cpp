//approach hai top se bottom tk jana hai
//ye triangle hai
//   2
//  3 4
// 6 5 7
//4 1 8 3

//minimum path nikalna hai

//Minimum Path Sum me moves the:
// right →
// down ↓

// Triangle me moves hain:
// down ↓
// down-right ↘

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int n=triangle.size();//Triangle me total rows count kar li.
        vector<int>dp=triangle[n-1];//Last row ko dp me copy kar liya:
        //Bottom se bottom tak ka minimum sum wahi element hai

        for(int i=n-2;i>=0;i--)//Second last row se top tak ja rahe hain:
//Row index: 2 → 1 → 0
        {

            for(int j=0;j<=i;j++)//Row ke har element ke liye calculate kar rahe hain.
            {
                dp[j]=triangle[i][j]+min(dp[j],dp[j+1]);
//                 Current element + niche ke dono possible paths me se minimum.
// Because allowed moves:
// (i,j) → (i+1,j)
// (i,j) → (i+1,j+1)
            }
        }
return dp[0];
        
    }
};