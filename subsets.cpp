//Array ke saare possible combinations bana do — including empty set
//The solution set must not contain duplicate subsets.


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int total=1<<n;//1 << n  =  2^n

        vector<vector<int>>ans;//kuki return time array of array or u can say vector of vector hai
        for(int mask=0;mask<total;mask++)
        {
            vector<int> subset;//array[] ya vector keh lo
            for(int i=0;i<n;i++)//hr element pe iterate krna hai
            {//lena hai ya nhi
            //dry run dekho--
            //mask = 0
             //binary = 000

                if(mask &(1<<i))//Ye binary me ith position par 1 set karta hai.
                {
//                     if(mask & (1<<i))
// Check karo:
// 0 & 001 = 0
// 0 & 010 = 0
// 0 & 100 = 0

//o mask k case me sike andar nhi ayega
                    subset.push_back(nums[i]);
                }
            }
            subset me empty push kr denge
            ans.push_back(subset);
        }
        return ans;

    }
};