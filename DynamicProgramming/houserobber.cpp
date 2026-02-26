//question hai tm ek chor ho
//aur line se 2 ghr hai
//Har ghar pe tumhare paas 2 choice hai:
// 1️⃣ Loot karo
// 2️⃣ Skip karo
//tm do adjacent ghr nhi loot skte
// Aur tumhe aisa choose karna hai ki total paise maximum ho.

//Maan lo hum house i pe khade hain.
//hmare paas 2 choice hai
//Loot karo
//Toh next wala (i+1) nahi loot sakte.
//Money = nums[i] + profit till (i-2)

//Skip karo
// Toh:
// Money = profit till (i-1)

//Recurrence Ban Gaya
// Ab dono me jo bada hoga wahi choose karenge:
// dp[i] = max(
//     dp[i-1],              // skip
//     nums[i] + dp[i-2]     // loot
// )


//Step 3: Base Cases

// Agar:
// i = 0
// dp[0] = nums[0]
// Agar:
// i = 1
// dp[1] = max(nums[0], nums[1])
// Kyuki dono adjacent hain, ek hi loot sakte hain.

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int prev2=nums[0];
        int prev1=max(nums[0],nums[1]);
        for(int i=2;i<n;i++)
        {
            int curr=max(prev1,nums[i]+prev2);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};