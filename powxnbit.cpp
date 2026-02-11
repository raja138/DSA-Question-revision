// Tumhe do cheezein di hui hain:
// x → ek double number
// n → ek integer
// Tumhe return karna hai:
// x^n return krna hai
// Matlab x ko n times multiply karna hai.

//take care of
//n negative ho sakta hai.
// n bohot bada ho sakta hai.
// Direct loop se multiply karna slow ho sakta hai.

// Basically Question:
// "Given x and n, efficiently calculate x raised to the power n."

//Sabse pehle basic socho

// Normal tareeka kya hoga?
// ans = 1
// for i = 1 to n:
//     ans *= x
// ⛔ Problem:
// Agar n = 10^9 hua to?
// Time complexity = O(n) → TLE
// To hume faster method chahiye.



class Solution {
public:
    double myPow(double x, int n) {
//         Pattern observe karo
// Example lete hain:
// 2^10
// Hum isko aise likh sakte hain:
// 2^10 = (2^5)^2
// 2^5  = 2 * (2^4)
// 2^4  = (2^2)^2
// Notice karo:
// Power ko half karte ja rahe hain.
        long long power=n;
        //n int hai.
// Agar n = -2^31 hua (INT_MIN)
// -n karte hi overflow ho jayega.
// Isliye:
// Pehle usko long long me store kiya.
        if(power<0)
        {

//             Kyu?
// Negative power ka matlab:
// 𝑥^−𝑛=1/𝑥^𝑛
// Example:
// 2^-3 = 1 / 2^3
// x = 1/x;
// power = -power;
// 👉 Kyu?
// Negative ko positive bana diya.
// Base ko invert kar diya.
// Ab problem normal positive power wali ho gayi.
            x=1/x;
            power=-power;//negative poer ko positive bna diya
        }
        double ans=1;
//         Power calculation me multiplication hota hai.
// Neutral element of multiplication = 1
// Isliye ans ko 1 se start kiya.
        while(power>0)//Jab tak power khatam nahi hoti tab tak calculate karte rahenge
        {

            //odd case hai
            .//Agar power odd hai to:

// 𝑥^𝑛=x*x^n-1
// Isliye ek baar extra multiply karna padega.
// ans *= x;
// Odd case me ek x answer me add kar diya.
            if(power%2==1)
            {
                ans*=x;
            }
            x*=x;
            //Ye kar raha hai:
             //𝑥*=𝑥 ka mtlb x=x^2
// Matlab next iteration me hum half power ke liye ready hain.
            power/=2;//Har step me power ko half kar rahe hain, isliye fast ho raha hai.
        }
        return ans;
    }
};