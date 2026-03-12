//fibonacci hai dp se
//pattern ye hai ki jb tk n less than equal to 2 hai to n ways
//otherwise picla aur usse pehle ka sum

class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;

        int prev1=2;
        int prev2=1;

        for(int i=3;i<=n;i++)
        {
            int curr=prev1+prev2;
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};