//Is question me tumhe ek string s di hoti hai, aur tumhe us string ke saare possible substrings (continuous parts) lene hote hain. Har substring ke liye tum beauty calculate karte ho, jiska matlab hai: us substring me jo character sabse zyada baar aaya ho uski frequency aur jo character sabse kam baar aaya ho (lekin at least ek baar) uski frequency ka difference. Fir tumhe sabhi substrings ki beauty ka total sum return karna hota hai. Single-character substrings ki beauty hamesha 0 hoti hai

class Solution {
public:
    int beautySum(string s) {

        // size of string hai
        //aur answer hoga
        //
        int n=s.size();
        int ans=0;


//Saare substrings lene hain
//Har substring ke liye:
//sabse zyada aane wala character (max freq)
//sabse kam aane wala character (jo exist karta ho, min freq)
//Har substring ka
//beauty = maxFreq − minFreq
//Sab beauties ka sum


//s = "aabcb"

//string pe iterate krte hai
        for(int i=0;i<n;i++){
            vector<int> freq(26,0);
// vector isliye rkh rhe hai ki  

//j = 0 → "a"
//j = 1 → "ab"
//j = 2 → "abc"
            for(int j=i;j<n;j++){

                freq[s[j] - 'a']++;
//  s[j] - 'a' se:
// character ka index milta hai
// Example:
// 'a' - 'a' = 0
// 'c' - 'a' = 2
// freq[s[j]-'a']++;

//mx → max frequency
//mn → min frequency (non-zero wali)


                int mx=0,mn=INT_MAX;
                for(int k=0;k<26;k++){
                    //Poora freq array scan kar rahe hain
//taaki:
//max freq
//min freq (but > 0)
//Jo character substring me exist hi nahi karta,
//use min me count nahi karna
                    if(freq[k]>0){
                        mx=max(mx,freq[k]);
                        mn=min(mn,freq[k]);
                    }
                }

                ans +=(mx-mn);
            }
        }
        return ans;
    }
};