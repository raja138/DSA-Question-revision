//Tumhe ek m × n matrix diya gaya hai.
//👉 Rule:
//Agar matrix ka koi bhi cell 0 ho
//To uski poori row aur poori column ko 0 bana do
//⚠️ In-place karna hai
//(matlab extra matrix use nahi karni)
//bgl me hjo picture hai use dekh lo 
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //int m = matrix.size();
       // matrix.size() kya deta hai?
       //Total number of rows
        int m=matrix.size();
        int n=matrix[0].size();

        //Ye yaad rakhne ke liye hai ki
        //original matrix ki first row / first column me koi 0 tha ya nahi
        bool firstRowZero=false;
        bool firstColZero=false;

        //ye check krega kya first column me zero hai
        for(int i=0;i<m;i++)
        {
            if(matrix[i][0]==0)
            {
                firstColZero=true;
                break;
            }
        }
        //ye check krega ki kya first row zero hai
        for(int j=0;j<n;j++)
        {
            if(matrix[0][j]==0)
            {
                firstRowZero=true;
                break;
            }
        }

        //ye marker lgayega aur 
        for(int i=1;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][0]==0 || matrix[0][j]==0)
                {
                    matrix[i][j]=0;
                }
            }
        }

        //firstRowZero



// 👉 Agar original first row me kahin bhi 0 tha,
// to:
// sirf first row ke saare elements 0 bana do
// 📌 Ye kisi aur column ko zero nahi karta
// 📌 Sirf matrix[0][j] (row 0) touch hota hai
        if(firstRowZero)
        {
            for(int j=0;j<n;j++)
            {
              
                    matrix[0][j]=0;
                
            }
        }

        //Agar original first column me kahin bhi 0 tha,
//to:
//sirf first column ke saare elements 0 bana do
//📌 Ye kisi aur row ko zero nahi karta
            if(firstColZero)
            {
                for(int i=0;i<m;i++)
                {
                    matrix[i][0]=0;
                }
            }
        }
    
};

// [
//  [1, 1, 1, 1],
//  [1, 0, 1, 1],
//  [1, 1, 1, 0],
//  [1, 1, 1, 1]
// ]