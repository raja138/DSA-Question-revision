//Question kya keh raha hai?
// Tumhe Roman numeral format me ek string di jayegi
// aur tumhe use normal integer (number) me convert karna hai.

class Solution {
public:
    int romanToInt(string s) {
        
        //map isliye liya hai kuki char and int ka map liya hai
        unordered_map<char,int>mp={
            {'I',1},
            {'V',5},{'X',10},{'L',50},{'C',100},
            {'D',500},{'M',1000}};

            //integer corresponding store krne k liye
        int ans=0;

        //iterate over the string 
        for(int i=0;i<s.length();i++){
            //Iska ek hi kaam hai:
            //Decide karna ki current Roman symbol ko ADD karna hai ya SUBTRACT
            //Roman Numeral ka Golden Rule
//Rule:
//Agar chhota number bada number se pehle aata hai → subtract
//Warna → add

//i+1 ye isliye kuki next and me s[i+1] use kr rhe hai
//


            if(i+1<s.length() && mp[s[i]]<mp[s[i+1]])
            {
                ans-=mp[s[i]];
            }
            else
            {
                ans+=mp[s[i]];
            }
        }

        // mp={
        //     {'I',1},
        //     {'V',5},{'X',10},{'L',50},{'C',100},
        //     {'D',500},{'M',1000}};

        
        return ans;
    }
};