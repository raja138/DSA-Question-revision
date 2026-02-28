//Tumhe ek array prices diya gaya hai,
// jisme prices[i] = i-th day ka stock price.
// 👉 Tumhara kaam hai maximum profit nikalna by:
// Sirf ek baar buy karna
// Sirf ek baar sell karna
// Buy hamesha sell se pehle hoga
// Agar koi profit possible nahi ho, to 0 return karo.
// 📌 Important points
// Buy aur sell same day nahi ho sakte
// Sirf ek transaction allowed
// Subarray / multiple transactions allowed nahi




class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int maxprofit=0;
        int n=prices.size();
//yha pe mujhe aya tha ki 
//max profit k liye piche waale se mini minus nhi ho paya
//pr question hi yhi hai ki pehle khareedo phr becho
//hum kosis kr rhe hai ki km me khareede aur baad me jada me beche
        for(int i=0;i<n;i++)
        {
            int cost = prices[i]-mini;
            maxprofit=max(maxprofit,cost);
            mini=min(mini,prices[i]);
        }
        return maxprofit;
    }
};