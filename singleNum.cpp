//mosina mam ne ye pdhaya tha ki
//saare numbers ka xor kro jo do br aaya hoga vo akhiri me bch jayega


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