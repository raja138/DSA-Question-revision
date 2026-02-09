// Tumhe ek integer array nums diya gaya hai.
// 👉 Given guarantee:
// Array me positive numbers aur negative numbers ki count equal hai
// nums.length even hai
// 🎯 Task (kya karna hai?)
// Array ko rearrange karo aise ki:
// Index 0 → positive
// Index 1 → negative
// Index 2 → positive
// Index 3 → negative
// …and so on

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        int posIndex=0,negIndex=1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<0)
            {
                ans[negIndex]=nums[i];
                negIndex +=2;

            }
            else{
                ans[posIndex]=nums[i];
                posIndex +=2;
                        }
        }
        return ans;
          }
};