// ek din buy karna hai
// aur ek din sell karna hai
// Condition:
// buy hamesha sell se pehle hona chahiye
// Goal:
// maximum profit find karna hai



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=INT_MAX;//Ye store karega ab tak ka sabse minimum price (best day to buy)
        int maxProfit=0;//Ye store karega ab tak ka maximum profit
        for(int price:prices)
        {
            minPrice=min(minPrice,price);//Sabse sasta buy price track kar rahe hain
            maxProfit=max(maxProfit,price-minPrice);
            //Aaj sell karke maximum profit update kar rahe hain

        }
        return maxProfit;
    }
};