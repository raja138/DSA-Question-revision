//Tumhe 2 numbers diye gaye hain:
// start
// goal
// Tumhe batana hai ki minimum kitne bits flip (0 → 1 ya 1 → 0) karne padenge taki start ko goal bana sako.

// start = 9   → 1001
// goal  = 14  → 1110
// Ab compare karo:
// 1001
// 1110
// ----
// 0111
// Jahan difference hai, wahi flip karna padega.
// 👉 Difference = total mismatched bits

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x= start^goal;
        //difference nikalne k liye
        int count=0;
        //Ab problem reduce ho gayi
// Original problem:
// Minimum bit flips?
// Ab new problem:
// (start ^ goal) me kitne 1s hain?
// Bas.

        while(x>0)
        {
            count+=(x&1);
            x>>=1;
        }
        return count;
    }
};

//Final Logical Flow
// XOR karo
// Set bits count karo
// Return count