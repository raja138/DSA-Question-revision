class Solution {

    //Question ka simple matlab 👇

// Tumhe ek string s di hui hai.
// Tumhe:
//har character ko count karna hai
//jo character zyada baar aaya hai, use pehle likhna hai
public:
    string frequencySort(string s) {
        //character  →  count
//Isliye data structure chahiye jo:
// key–value store kare
// fast ho
// har character ke liye count badha sake
        unordered_map<char,int>freq;

        //ab har character pe iterate krte hai aur uski
        for(char c:s)
        {
            freq[c]++;
        }

        vector<pair<char,int>> vec(freq.begin(),freq.end());
        
        //upr na ek vector pair bna rhe hai 
        //isme kya kr rhe hai ki 
        //map se char nikal kr uska count bdha rhe hai


        //Ye line overall kya karti hai?
        //vec ko frequency (second) ke basis par descending order me sort karti hai
        sort(vec.begin(),vec.end(),[](auto&a,auto&b){//Sort all characters such that    the character with higher frequency comes first.
             return a.second>b.second;//compare ('t',1) & ('r',1) → equal → order doesn't matter
//compare ('e',2) & ('t',1) → 2 > 1 → 'e' aage
        });


        string result="";
        //ab result bhi return karna hai

        for(auto &p:vec)//vector pe iterate kr ke //srf vector pe iterate krne se 
        {            //copy na bna kr direct utha lo
            result.append(p.second,p.first);
        }

        //return kr do result
        return result;
    }
};