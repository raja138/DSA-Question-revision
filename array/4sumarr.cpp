//Mental model (yaad rakhne ke liye)
//2Sum → two pointers
//3Sum → fix 1 + two pointers
//4Sum → fix 2 + two pointers


// Pehle 3Sum ko “formula” bana lo
// 3Sum ka mental formula:
// Sort
// Fix i
// Two pointers (l, r)
// Skip duplicates


// 4Sum ka mental formula:
// Sort
// Fix i
// Fix j
// Two pointers (k, l)
// Skip duplicates



class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;j++)
            {
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int k=j+1;
                int l=n-1;
                while(k<l)
                {
                    long long sum=(long long)nums[i]+nums[j]+nums[k]+nums[l];
                    if(sum==target)
                    {
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;
                        while(k<l && nums[k]==nums[k-1]) k++;
                        while(k<l && nums[l]==nums[l+1]) l--;
                    }
                    else if(sum<target)
                    {
                        k++;
                    }
                    else
                    {
                        l--;
                    }
                }
            }
        }

        return ans;

        
    }
};