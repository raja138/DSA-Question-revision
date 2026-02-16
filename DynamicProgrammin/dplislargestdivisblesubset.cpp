//bhai ye question keh rha hai
//tmhe ek array diya hai
//ab tmhe ek subset find karna hai
//subset ka mtlb hota hai kisi bhi order me
//jisme hr pair k liye
//a,b a%b ==0 ya b%a==0
//subset ke har 2 numbers divisible hone chahiye (ek dusre se)
//goal h largest possible subset find karna
//kuch elements choose kar sakte ho
// order matter nahi karta
// continuous hona zaroori nahi

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        //agra array sorted hoga to
        //srf ye check karna enough hoga ki 
        //nums[i] % nums[j] == 0   (j < i)
        sort(nums.begin(),nums.end());
        //dp se kr rhe hai to dp define kro
        //initially dp[i]=1 kuki har element khud me subset hai
        vector<int>dp(n,1);//dp[i] = largest divisible subset size ending at index i
        vector<int>parent(n,-1);
        //// parent[i] store karta hai previous index of nums[i] in divisible subset chain
// isse baad me actual subset reconstruct kar sakte hain
        int maxSize=1;
        int maxIndex=0;
        //maxSize aur maxIndex ka use largest subset kaha end ho raha hai wo find karne ke liye hota hai.


        //// Har element ke liye previous sab elements check karte hain
// Agar nums[i], nums[j] se divisible hai to chain extend kar sakte hain
// dp[i] update karte hain new subset size ke saath
// parent[i] store karta hai chain ka previous index
// maxSize aur maxIndex largest subset track karte hain
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j] == 0 && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    parent[i]=j;
                }
            }
        ///// Agar current subset size sabse bada hai,
// to maxSize update karo aur maxIndex store karo
// maxIndex se baad me subset reconstruct karenge
        if(dp[i]>maxSize)
        {
            maxSize=dp[i];
            maxIndex=i;

        }
        }

//Ye code parent array use karke actual largest divisible subset reconstruct kar raha hai.
        vector<int>result;
        while(maxIndex!=-1)
        {
            //mera question tha ki ye km kaise ho rhi hai maxIndex?
            //ans
            //// maxIndex ko parent[maxIndex] se update kar rahe hain,
// isse chain me peeche move karte hain (index automatically chota hota hai)
            result.push_back(nums[maxIndex]);
            maxIndex=parent[maxIndex];
        }

//Ye line use ho rahi hai kyunki hum subset reverse order me build kar rahe the, ab usko correct order me lana hai.
        reverse(result.begin(),result.end());
        return result;
    }
};

// Step 1: Array sort karo
// Step 2: dp[i] = largest divisible subset ending at i
// Step 3: Agar nums[i] % nums[j] == 0, to dp[i] update karo
// Step 4: Maximum dp value find karo
// Step 5: Parent array se subset reconstruct karo