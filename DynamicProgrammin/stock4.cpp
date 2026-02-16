// Tumhe diya hai:
// k → maximum number of transactions allowed
// prices → har din ka stock price
// Tum:
// Buy kar sakte ho
// Sell kar sakte ho
// BUT maximum k transactions hi allowed hain
// Aur ek important rule:
// 👉 Ek time pe sirf 1 stock hold kar sakte ho

//Maximum profit find karo using at most k buy-sell pairs


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;

        //maximum transaction kitne ho skte hai
        //one day buy and one day sell so 2
        //to max transaction n/2
        //to if(k >= n/2)
//         allowed transactions >= maximum possible transactions
// Matlab tum unlimited transactions kar sakte ho effectively.
// Unlimited transactions me best strategy kya hoti hai?
// Simple greedy:
// Jab bhi price badhe, profit le lo.
        if(k >= n/2) {
            int profit = 0;
            for(int i = 1; i < n; i++) {
                if(prices[i] > prices[i-1])
                    profit += prices[i] - prices[i-1];
            }
            return profit;
        }
        vector<int> buy(k+1, INT_MIN);
        vector<int> sell(k+1, 0);
        for(int price : prices) {
            for(int t = k; t >= 1; t--) {  
                sell[t] = max(sell[t], buy[t] + price);
                buy[t] = max(buy[t], sell[t-1] - price);
            }
        }
        
        return sell[k];
    }
};
