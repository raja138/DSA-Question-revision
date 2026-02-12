// House Robber II exactly House Robber I jaisa hi hai —
// 🔁 Bas difference itna hai ki houses circular hain.

//chalo ab approach sochte hai
//to ab robber 1 ki trh first hmesha include nhi hoga
//ya to first include hoga ya nhi hoga

//-->>to case bnenege 
//1) agar first ko include kr rhe hai to last automatically  exclude kr do
//range = [0 → n-2]
//Ye normal robber 1 jaisa hai
//2)first exclude kro to last include kr skte ho
//range = [1 → n-1]
//final step--
//max(case1,case2)


//edge case agar 1 house ho to [5] to answer 5 hoga
//if(n==1) return nums[0];
class Solution {
public:
int robLinear(vector<int>& nums,int start,int end)
{
    int prev2=0;
    int prev1=0;
    for(int i=start;i<=end;i++)
    {
        int curr=max(prev1,nums[i]+prev2);
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];

        int case1=robLinear(nums,0,n-2);
        int case2=robLinear(nums,1,n-1);
        return max(case1,case2);
    }
};