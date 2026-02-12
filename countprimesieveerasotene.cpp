//sieve of erasothenes
//Tumhe ek integer n diya gaya hai.
// Tumhe check karna hai n se chhote numbers me kitne prime numbers hain.
// "Strictly less than n" ka matlab → n khud include nahi hoga.
// Prime number wo hota hai jo sirf 1 aur khud se divisible ho.
// Final output ek integer hoga — total prime numbers ka count.

class Solution {
public:
    int countPrimes(int n) {
        
        if(n<=2) return 0;
        vector<bool> isPrime(n,true);
        isPrime[0]=false;
        isPrime[1]=false;

        for(int i=2;i*i<n;i++)
        {
            if(isPrime[i]){
                for(int j=i*i;j<n;j+=i)
                {
                    isPrime[j]=false;
                }
            }
        }

        int count=0;

        for(int i=2;i<n;i++)
        {
            if(isPrime[i]) count++;
        }

        return count;
    }
};