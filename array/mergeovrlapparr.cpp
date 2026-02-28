//Question (simple words me)
// Tumhe ek list di gayi hai jisme intervals hain.
// Har interval ek pair hota hai:
// [start, end]
// Tumhara kaam hai:
// 👉 Jo intervals overlap karte hain, unko merge karke
// 👉 final list return karni hai jisme koi overlap na ho
// 📌 Important baatein
// Intervals unordered ho sakte hain
// Overlapping intervals ko combine karna hai
// Output me non-overlapping intervals hone chahiye
// Order output me sorted hi hota hai (start time ke hisaab se)
// 🔍 Example 1
// Input:  [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n=arr.size();
        //Sabse pehle kya karna padega?
// ❓ Overlap kaise pehchaanoge?
// Intervals unordered hain.
// 👉 Isliye sorting mandatory hai
// (start time ke hisaab se)
// sort(intervals.begin(), intervals.end());
        sort(arr.begin(),arr.end());
        //vector<vector<int> return type hai
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {

            //Case 1: Pehla interval ya no overlap
// if (ans empty OR current.start > last.end)
// 👉 Matlab:
// Ya to ans khali hai
// Ya current interval pichhle se alag hai


//arr = [[1,3],[2,6]]
//arr[i][0]--pehle element dega ye array of array hai na 
//ya keh lo vector of vector hai

//ans jo hai merged interval ka vector hai
//ans.back()[1]---last interval ka end
//example
//ans = [[1,6],[8,10]]
// Values:
// ans.back() = [8,10]
//ans.back()[0]--ye kya dega 8
// ans.back()[1] = 10
//arr = [[1,3],[2,6],[8,10],[15,18]]
// 🔹 arr[i][0] kya deta hai?
// 👉 Current interval ka START
// Example:
// i = 0 → arr[0][0] = 1


            if(ans.empty() || arr[i][0]>ans.back()[1])
            {
                //New interval start karo
                //ans.push_back(current);
                ans.push_back(arr[i]);
            }
            else
            {
                // Case 2: Overlap hai
                // else
                // 👉 Matlab:
                // current.start <= last.end
                // ➡️ Merge karo
                // last.end = max(last.end, current.end);

                //arr[i][1] kya deta hai?
                // 👉 Current interval ka END
                // Example:
                 // i = 0 → arr[0][1] = 3
                ans.back()[1]=max(ans.back()[1],arr[i][1]);
            }

        }
        return ans;
        
    }
};