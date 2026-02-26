// Tumhe ek unsorted integer array diya gaya hai.
// 👉 Tumhara kaam hai sabse lambi sequence nikalna jo:
// Consecutive numbers ki ho
// (har next number = previous + 1)
// Numbers continuous hone chahiye,
// lekin array me adjacent hona zaroori nahi
// Order matter nahi karta
// Sirf length return karni hai, sequence nahi

// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

//Array unsorted hai

// Duplicates ho sakte hain
// Expected solution O(n) time me hona chahiye
// (sorting allowed nahi)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());//not sorted its random only
        //unordered_set kyun BEST hai?
// unordered_set<int> st;
// Perfect match because:
// Requirement	unordered_set
// Fast lookup	O(1)
// Only existence	✔️
// No duplicates	✔️
// No order needed	✔️
// Low memory	✔️
        int longest=0;
        for(int num:st)
        {
            if(st.find(num-1)==st.end())//bhai ye ye check kr rha hai ki
            //num-1 set me exist krta hai ya nhi
            //num-1 st.end ka mtlb st.end comparison and all

            //num-1 isliye liya hai taaki ye pta lag ske ki 
            //us number se pehle number exist to nhi karta agar krta hoga to vo pehle hi sequence bna chuka hoga 
            {
                //ab vo wala logic ki num k aage waala sequence exist krta hai kya??
                int currNum=num;
                int count=1;
                while(st.find(currNum+1)!=st.end()){
                    currNum++;
                    count++;
                }
                longest=max(longest,count);
            }
        }
        return longest;

    }
};