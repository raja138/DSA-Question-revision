//index se start krke aage bdho aur phr jo bhi partition aaye
//usse use krkr 
//suno simple ho kya rha hai array pe jaao
//ek ek krke phr array ka partition kro atmost k length tk ka
//phr us partition me jo bhi elem max ho usse replace kr do sbko aur sum kro
//बिल्कुल! जब तुम हर पार्टिशन बना रहे हो, उस हिस्से का मैक्सिमम चुनकर उसे पूरे हिस्से में भरोगे, फिर उस हिस्से का जोड़ निकालोगे। आखिर में, इन सारे हिस्सों के जोड़े मिलाकर तुम्हें पूरा कुल जोड़ मिलेगा, और यही तुम्हारा अंतिम जवाब होगा।




class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();//loop pe iterate klrne k liye
        vector<int> dp(n + 1, 0);//n+1 size ka vector 0 se initialise
        //

        for(int i = n - 1; i >= 0; i--) {//piche se easy hota hai
            int maxi = 0;//particular hisse me max number yad rkhne k liye
            int ans = 0;//sbse bda sum us hisse ka store krne k liye
            //jb hum ek le dusra le ya teesra le


            //

            for(int j = i; j < min(n, i + k); j++) {
                maxi = max(maxi, arr[j]);
                ans = max(ans, maxi * (j - i + 1) + dp[j + 1]);
            }

            dp[i] = ans;
        }

        return dp[0];
    }
};