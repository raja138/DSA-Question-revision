// (Question simple words me)
// Tumhe ek n × n (square) matrix diya gaya hai.
// Tumhara kaam hai is matrix ko 90° clockwise rotate karna.
// Important condition
// Rotation in-place honi chahiye
// Koi extra matrix use nahi kar sakte

//logic--

//Observe the pattern
//Original → Rotated mapping
//matrix[i][j]  →  matrix[j][n-1-i]


// Direct mapping problem
// Agar directly upar wali mapping use karo:
// Ek extra matrix chahiye 
// In-place allowed nahi 

//In-place trick dhoondo
//Observation:
//Rotate = Transpose + Reverse rows

//Transpose kyun?
//Transpose means:
//matrix[i][j] ↔ matrix[j][i]
//Example:
// 1 2 3      1 4 7
// 4 5 6  →   2 5 8
// 7 8 9      3 6 9
// 👉 Row → Column ban gaya
// 🧠 Step 6: Reverse rows kyun?
// Transpose ke baad:
// 1 4 7
// 2 5 8
// 3 6 9
// Row reverse:
// 7 4 1
// 8 5 2
// 9 6 3
// 👉 Exactly 90° clockwise result 🎯

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();

        //transpose
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        //reverse

        for(int i=0;i<n;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};