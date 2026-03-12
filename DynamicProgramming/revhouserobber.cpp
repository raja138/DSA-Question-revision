class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];//ye galat k rhe the dekh lena

        int twohouseback=nums[0];//pehle twohouse hoga
        int onehouseback=max(nums[0],nums[1]);//phr one house hoga

        for(int i=2;i<nums.size();i++)
        {
            int current=max(onehouseback,
                             twohouseback+nums[i]);
            twohouseback=onehouseback;
            onehouseback=current;                 

        }

        return onehouseback;
    }
};