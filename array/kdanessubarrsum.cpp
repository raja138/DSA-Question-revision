// Tumhe ek integer array diya gaya hai
// (jisme positive, negative, dono ho sakte hain).

// 👉 Tumhara kaam hai ek continuous subarray (lagatar elements) dhundhna
// jiska sum sabse zyada h


//Subarray continuous hona chahiye
//Kam se kam 1 element include hoga
//Sirf maximum sum return karna hai

//Subarray jo answer bana:
//[4, -1, 2, 1]
//Jahan bhi sum negative hua:
//-2, -3
// wahan se subarray tod diya (sum = 0)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long maxi=LLONG_MIN;
        long long sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum>maxi)
            {
                maxi=sum;
            }

            //Jahan bhi sum negative hua:
            //-2, -3
            // wahan se subarray tod diya (sum = 0)
            if(sum<0)
            {
                sum=0;
            }
        }
        return maxi;
    }
};