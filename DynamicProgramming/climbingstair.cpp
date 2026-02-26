//Question kya keh raha hai?
// 1️⃣ Tumhare paas n stairs hai (maan lo 5 stairs).
// 2️⃣ Har baar tum ya to 1 step chadh sakte ho ya 2 step.
// 3️⃣ Tumhe top tak pahunchna hai.
// 4️⃣ Pata karna hai — kitne alag-alag tareeke se tum upar pahunch sakte ho?

//basically ye fibonacci ka question hai dp se
//kuki constraint iase hai

class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;//agar n=1 to 1 way
        //agar n=2 to 2 ways
        int prev2=1;//ye represent krta hai ways ki 1 stair chadne k total ways kitne??
        int prev1=2;//2 stair chadne k ways kitne
        for(int i=3;i<=n;i++)
        {
            //Ab hum 3 se lekar n tak
            //har stair ke liye total ways calculate karenge.
            //Ab hum 3 se lekar n tak
// har stair ke liye total ways calculate karenge.
// int curr=prev1+prev2;
// Yaha main logic hai 🔥
// ways(i) = ways(i-1) + ways(i-2)
// prev1 → ways(i-1)
// prev2 → ways(i-2)
// Dono ko add kiya = current stair ke total ways.
// prev2=prev1;
// Shift kar rahe hain values:
// Ab old prev1 ban jayega new prev2
// prev1=curr;
// Ab current value ban jayegi new prev1
// Isse next iteration ke liye values ready ho jaati hain.
// return prev1
// Loop khatam hone ke baad
// prev1 me store hota hai:
//return prev


            int curr=prev1+prev2;
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};