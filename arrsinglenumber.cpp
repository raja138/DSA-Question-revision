class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a=0;

        for(int i=0;i<nums.size();i++)
        {
            a^=nums[i];
        }

        return a;
    }
};


//simple hai 
//Tumhe ek array nums diya hai jisme:
//har element exactly 2 baar aata hai
//sirf ek element aisa hai jo 1 baar aata hai
//Tumhe wahi single element return karna hai.