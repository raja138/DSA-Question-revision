class Solution {

    //Question kya bol raha hai?
//Tumhe ek string s di jaayegi.
//Tumhe us string ko integer (number) me convert karna hai — bilkul C/C++ ke atoi() function jaisa.


public:
    int myAtoi(string s) {
        int i=0,n=s.size();

        //Iska kaam kya hai?


        while(i<n && s[i]==' '){
            i++;
        }
//  String ke aage jo extra spaces hain unko skip karna
// Matlab:
// Jab tak space mil rahi hai
// Aur string ke bahar nahi gaye (i < n)
// Tab tak i aage badhate raho

        int sign=1;

// Sign decide karna
// sign = (s[i] == '-') ? -1 : 1;
// Agar '-' mila → number negative
// Agar '+' mila → number positive

        if(i<n && (s[i]=='+' || s[i]=='-')){
            sign=(s[i]=='-')?-1:1;
            i++;
        }


        long long num=0;
        while(i<n && isdigit(s[i])){
            //s[i]-'0'

            //ascii value ko 0 se minus krne pe exact velue mil jaati hai
            //'7' - '0' = 55 - 48 = 7
            //true → agar character '0' se '9' ke beech ho
//false → agar kuch aur ho

            num=num*10 + (s[i]-'0');
            //Positive number banate waqt integer overflow se bachne ke liye
            if(sign==1 && num> INT_MAX){
                return INT_MAX;
            }

            //Negative number banate waqt overflow (underflow) se bachne ke liye
            if(sign==-1 &&-num < INT_MIN)
            {
                return INT_MIN;
            }
            i++;
        }

        //positive ya negative kaisa number hai ye sign se multiply krne k liye
        return sign*num;
    }
};