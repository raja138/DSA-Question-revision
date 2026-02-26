//Tumhe ek grid diya hai:
// Size = m x n
// Tum start karte ho top-left corner se
// Tumhe pahunchna hai bottom-right corner tak
//Tum start karte ho top-left corner (0,0) se
//Tumhe pahunchna hai bottom-right corner (m-1, n-1) tak



class Solution {
public:
    int uniquePaths(int m, int n) {
//m = 3
// n = 3

?  ?  ?
?  ?  ?
?  ?  ?

// Cell (1,1) tak kaise aa sakte hain?
// Sirf 2 jagah se:
// Upar se → (0,1)
// Left se → (1,0)
// Matlab:
// ways(1,1) = ways(0,1) + ways(1,0)
//ways(i,j) = ways(i-1,j) + ways(i,j-1)

// Kyuki allowed moves sirf:
// Down
// Right


//Base Case

// First row:
// Tum sirf right move karke pahunch sakte ho.
// Toh:
// [1 1 1]
// First column:
// Sirf down move karke.
// 1
// 1
// 1
//  Step 5: Fill Table
// Start table:
// 1 1 1
// 1 ? ?
// 1 ? ?

// Now calculate:
// (1,1) = 1 + 1 = 2
// (1,2) = 2 + 1 = 3
// (2,1) = 1 + 2 = 3
// (2,2) = 3 + 3 = 6
// Final:
// 1 1 1
// 1 2 3
// 1 3 6

        vector<int>dp(n,1);
        for(int i=1;i<m;i++)
        {
        for(int j=1;j<n;j++)
        {
         dp[j] +=dp[j-1];
        }
        } 
        return dp[n-1];
    } 
};