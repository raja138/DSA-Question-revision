// Tumhe ek integer array nums diya gaya hai.
// Tumhara kaam hai saare unique triplets (3 numbers ke group) dhoondhna jinke liye:
// a + b + c = 0
// Important baatein (dhyaan se)
// Triplet = 3 different indices ke elements
// Order matter nahi karta
// [-1,0,1] same as [0,1,-1]
// Duplicate triplets allowed nahi
//Order different ho tab bhi allowed nahi hai
// [-1, 0, 1]
// [1, 0, -1]
// 👉 Dono SAME triplet maane jaate hain
// 👉 Allowed nahi (duplicate triplet)
// Array unsorted ho sakta hai
// Output me sirf unique triplets chahiye


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        {
        vector<vector<int>>ans;//vector of vector lena hai isliye ans vector of vector lena hai
        //[[-1,-1,2],[-1,0,1]]
        int n=nums.size();
        //n kuki niche loop me lgayenge
        sort(nums.begin(),nums.end());
        //sort kr lo array
        //two pointer srf sorted pe lagta hai 
        //aur duplicates ko skip krne k liye 
        //ye line dekho  if(i>0 && nums[i]==nums[i-1]) continue;
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            int left=i+1;
            int right=n-1;
            while(left<right)
            {
                int sum=nums[i]+nums[left]+nums[right];
                if(sum==0)
                {
                    ans.push_back({nums[i],nums[left],nums[right]});
                    while(left<right && nums[left]==nums[left+1]) left++;

                    while(left< right &&nums[right]==nums[right-1]) right--;

                    left++;
                    right--;
                }
                else if(sum<0)
                {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        return ans;
    }
    }
};
//me jo smjha vo ye hai ki
//isme two pointer lgega aur 
//duplicates skip krenge
//iterate kro i pe 
//phr two pointer chlayenge sum krenge
//agr sum mil gya to push krenge aur aage dekhnegne 
//duplicate hai ya nhi
//agar  hai to skip nhi to aage based on sum aage left ya right ko increment decrement krenge