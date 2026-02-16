// Hume stock prices aur ek transaction fee di gayi hai.
// Hum multiple times buy aur sell kar sakte hain, but har sell par fee lagegi.
// Kisi bhi time par ya to hum stock hold kar rahe honge ya nahi.
// Goal: har sell par fee dene ke baad maximum total profit find karna hai.


//har din tmare paas do choice hai
//1. Stock hold karna
//Stock hold na karna (cash me rehna)

// hold → max profit jab stock hold kar rahe ho
// cash → max profit jab stock hold nahi kar rahe ho


class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();//ye to saare stock problem me h
        //ye day 0 k l;iye hai
        int hold=-prices[0];//buy kiya
        int cash=0;//kuch nhi kiya

        for(int i=1;i<n;i++)
        {
            //cash → profit jab stock hold nahi kar rahe
//hold → profit jab stock hold kar rahe
//cash aane k do option hai
// ya to cash hai ya to
// price[i]-fee hai
            cash=max(cash,hold+prices[i]-fee);
            //Ya to kuch mat karo
             //Ya stock buy karo
            hold=max(hold,cash-prices[i]);
            //hold state me aane k do option hai
            //ya to hold ya to aaj buy kro
            //tmare cash me se us din ka price minus
        }
        //final answer cash return kro kuki stock hold
        //nhi karna chahte
        //
        return cash;
    }
};