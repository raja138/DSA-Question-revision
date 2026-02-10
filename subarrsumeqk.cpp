//Tumhe ek integer array nums aur ek integer k diya gaya hai.
// Tumhara kaam hai count karna ki kitne subarrays ka sum exactly k ke barabar hai.

//Important points (dhyaan se)
//Subarray = continuous part of array
//(beech me gap allowed nahi)
//Order same rehna chahiye
//Duplicates allowed hain
//Subarray ka size kuch bhi ho sakta hai (1 se n tak)
//Sirf count return karna hai, longest ya length nahi

// We use prefix sums and a hashmap to count how many times a required sum has appeared so far.
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        //mp[0] = 1 ka matlab:
//Array start hone se pehle ek prefix sum = 0 already exist karta hai.
        int sum=0;
        int count=0;

        // nums = [1,1,1], k = 2
//         sum = 0
// count = 0
// mp = { 0 : 1 }
        for(int x:nums)
        {
            sum+=x;
            //1-->>x hai 1 , sum hai 0 to sum+=x. o+1=1 to sum 1 ho gya
            //2--->>x hai 1,sum hai 1 pehle level pe aur sum ho gya 2 ab
            //3--->> sum ki value 2 thi  x 1 hai to sum ho jayega 3
            //2-->sum-k-- sum hai 2 k hai 2 to sum-k=0 map hai 
            //2-->>{0:1, 1:1} // mp .find(0) to 0 hai isme to 
            //3-->sum-k ho jayega sum hai 3 k hai 2to sum-k ho jayega 3-2=1
            //3--->> map hai {0:1, 1:1, 2:1} mp[1] hai 1 to if k andar
            if(mp.find(sum-k)!=mp.end())//1-->>sum hai 1 k hai 2 to sum-k ho jayega 1-2 =-1 aur map hai  { 0 : 1 } to -1 to hai hi  
            //1--->>ye skip ho jayega
            {
                //2-->> me ye if k andar aa jayega
                //3-->count pehle se hai 1 mp[sum-k] sum hai 3 3-2=1
                //3 ab 1+=mp[1] 1+=11 to count 2 ho jayega
                count+=mp[sum-k];//2--->>mp[sum-k]---mp[0] se milage 1
                //2-->>count ho jayega 1
            }
            mp[sum]++;//1--sum 0 hai mp[sum] kya hai ye hai mp[0] haiu 1 to mp[1] ho jayega 1 now map will be {0:1, 1:1}
            //2-->>mp[2] ho jayega 1 // nya map---{0:1, 1:1, 2:1}

            //3-- sum hai to map me 3 pe 1 ho jayega

            //3-->>{0:1, 1:1, 2:1,3:1}

            //3-->>count 2 aur return

        }
        return count;
    }
};
//chat gpt ka dry run agar upr wala na smjh aaye to
// ---------- LEVEL 1 ----------
    // x = 1
    // sum = 0 + 1 = 1
    // sum - k = 1 - 2 = -1
    // mp me -1 exist nahi karta
    // isliye count change nahi hoga (count = 0)
    // mp me sum store karenge
    // mp = {0:1, 1:1}

    // ---------- LEVEL 2 ----------
    // x = 1
    // sum = 1 + 1 = 2
    // sum - k = 2 - 2 = 0
    // mp[0] = 1 (exist karta hai)
    // count = 0 + 1 = 1
    // mp me sum store karenge
    // mp = {0:1, 1:1, 2:1}

    // ---------- LEVEL 3 ----------
    // x = 1
    // sum = 2 + 1 = 3
    // sum - k = 3 - 2 = 1
    // mp[1] = 1 (exist karta hai)
    // count = 1 + 1 = 2
    // mp me sum store karenge
    // mp = {0:1, 1:1, 2:1, 3:1}