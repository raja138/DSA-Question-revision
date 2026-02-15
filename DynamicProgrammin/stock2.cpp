// Tum:
// multiple times buy and sell kar sakte ho
// But rule:
// Sell karne ke baad hi dubara buy kar sakte ho
// Ek time par:
// sirf 1 stock hold kar sakte ho

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;


        for(int i=1;i<prices.size();i++)
        {
            //Har price increase par buy karke sell kar rahe hain aur profit add kar rahe hain.
            if(prices[i]>prices[i-1])
            {
                profit+=prices[i] - prices[i-1];
            }
        }

        return profit;
    }
};