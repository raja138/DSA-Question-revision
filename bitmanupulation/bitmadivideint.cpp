// Question Kya Keh Raha Hai?
// Tumhe do integers diye gaye hain:
// dividend  → jisko divide karna hai  
// divisor   → jisse divide karna hai
// Tumhe return karna hai:
// quotient = dividend / divisor
// Lekin ❗
// ❌ Tum use nahi kar sakte:=
// multiplication (*)
// division (/)
// modulo (%)
// 🔹 Division ka matlab kya hai yahan?
// 1️⃣ Truncate toward zero
// Matlab decimal part hata do.
// Examples:
// 8 / 3  = 2.66 → 2
// -8 / 3 = -2.66 → -2
// Notice:
// Floor nahi karna
// Bas decimal cut karna hai
// 🔹 Important Condition (Very Important)
// System 32-bit integer store karta hai:
// Range: [-2^31 , 2^31 - 1]
// Matlab:
// Minimum = -2147483648
// Maximum =  2147483647
// Agar answer is range se bahar chala gaya:
// Greater than max → return 2147483647
// Less than min → return -2147483648
// 🔹 Sabse Dangerous Edge Case
// dividend = -2147483648
// divisor = -1
// Normally:
// -2147483648 / -1 = 2147483648
// But ❗
// 2147483648 range ke bahar hai.
// Toh answer hona chahiye:
// 2147483647
// 🔹 Tumse Actually Kya Expect Kar Rahe Hain?
// Interviewer check karna chahta hai:
// Kya tum multiplication ko bit shifting se replace kar sakte ho?
// Kya tum overflow handle kar sakte ho?
// Kya tum negative sign logic samajhte ho?
// Kya tum O(N) solution nahi banaoge?
// 🔹 Simple Example Samjho
// Example 1:
// dividend = 10
// divisor = 3
// Mathematically:
// 10 / 3 = 3.33
// Return:
// 3
// Example 2:
// dividend = -7
// divisor = 2
// Math:
// -7 / 2 = -3.5
// Return:
// -3
// (decimal remove, floor nahi karna)
// 🔹 Core Idea Simplified
// Division ka matlab hota hai:
// 10 / 3 = kitni baar 3 ko subtract kar sakte ho 10 se?
// 10 - 3 = 7
// 7 - 3 = 4
// 4 - 3 = 1
// Total 3 baar subtract hua → answer 3
// But repeatedly subtract karna slow hai.
// Isliye hum:
// 👉 Large chunks subtract karte hain
// 👉 Bit shifting use karte hain
// 🧠 Short Summary (Interview Style)
// We need to compute quotient using subtraction and bit shifting while handling sign and 32-bit overflow constraints.

//We need to compute quotient using subtraction and bit shifting while handling sign and 32-bit overflow constraints.


class Solution {
public:
    int divide(int dividend, int divisor) {
        //Divide two integers without using * / %
// Truncate toward zero
// Handle 32-bit overflow

        //Since INT_MIN is -2^31 and INT_MAX is 2^31 - 1, dividing INT_MIN by -1 results in 2^31, which exceeds the 32-bit signed integer range. Therefore, we return INT_MAX explicitly to prevent overflow.
        if(dividend == INT_MIN && divisor == -1)
        {
            return INT_MAX;
        }

        //dividend <0 dividedn>0 true ya false dega
        //aur phr xor kya krega agar ek bhi true to true

        //negative → result ka sign store karta hai
         //a → positive dividend
         //b → positive divisor
            bool negative =(dividend<0)^(divisor<0);
            //llabs kya karta hai?
            //llabs() = long long absolute function


            //Type casting
            // (long long) dividend
           // Kyun?
            // Kyuki:
            // INT_MIN = -2147483648
            // Agar tum abs(INT_MIN) karoge in int:
            // ⚠ overflow ho jayega.
            // Kyuki +2147483648 store nahi ho sakta int me.
            // Isliye pehle convert karte hain:
            // int → long long

            long long a=llabs((long long)dividend);
            long long b=llabs((long long)divisor);
            long long ans=0;
             
//              Division ka matlab:
// a / b = kitni baar b ko subtract kar sakte ho a se
// Naive tareeka:
// while(a >= b){
//     a -= b;
//     count++;
// }
// ❌ Slow hai (O(N))
// Isliye hum ek smart kaam karte hain:
// 👉 Har baar maximum possible multiple of b subtract karte hain




                while(a>=b)//Jab tak dividend (a) divisor (b) se bada hai,tab tak subtract karte raho.
                {
                    long long temp=b,multiple=1;
                    //temp = divisor ka current multiplied version
                    //multiple = kitna times multiply kiya hai

                    //Kya kar raha hai?
                 
                    while((temp << 1)<=a)
                    {
                        temp<<=1;//temp << 1 matlab:
                                 //temp * 2
                             //Toh hum dekh rahe hain:
//Kya divisor ka double version bhi a ke andar fit ho sakta hai?
//Jab tak fit ho raha hai,
//double karte raho.
                        multiple <<=1;
                    }
                    a-=temp;
                    ans +=multiple;
                }

                if(negative) ans=-ans;

                if(ans> INT_MAX) return INT_MAX;
                if(ans<INT_MIN) return INT_MIN;

                return(int)ans;
            }
        
};

//core logic--
// Division ko hum repeated subtraction me convert kar rahe hain.
// Lekin slow subtraction ki jagah, hum divisor ko double karte ja rahe hain (bit shifting se) taaki ek hi step me bada chunk subtract kar saken.