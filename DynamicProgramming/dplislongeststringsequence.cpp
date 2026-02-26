// Next word previous word se exactly 1 extra character add karke bana hona chahiye, baaki sab same order me hone chahiye.

//"a" → "ba"
// Explanation:
// "a" me 'b' add hua → "ba"
// Valid 
// "ba" → "bca"
// Explanation:
// "ba" me 'c' add hua → "bca"

//Exactly LIS pattern, bas condition hai string me 1 extra character hona chahiye

//Ye function check karta hai ki kya string b, string a ka predecessor chain me next word ho sakta hai ya nahi.
class Solution {
public:
    bool isPredecessor(string &a,string &b) {
        if(b.size()!=a.size() + 1) return false;//Next word me exactly 1 extra character hona chahiye
        int i=0,j=0;
        //Two pointers:
// i → string a ke liye
// j → string b ke liye


//Hum b ke saare characters check karenge.
        while(j<b.size())
        {
            if(i<a.size() && a[i]==b[j])
            {
                i++;//Agar characters match kare → dono pointers move
            }
                j++;//
//Agar match na kare → sirf j++
//Iska matlab extra character skip ho raha hai
            
        }
            return i==a.size();//agar a ke saare characters match ho gaye
//to valid predecessor hai
        }



        //// Step 1: words ko length ke basis par sort karo
// Step 2: dp[i] store karega longest chain ending at words[i]
// Step 3: har word ke liye previous words check karo
// Step 4: agar predecessor hai to dp[i] update karo
// Step 5: maximum dp value return karo
    
        int longestStrChain(vector<string>& words)
        {
            int n=words.size();
            //Matlab chain hamesha small length → large length me banegi.
// So first step:
sort(words.begin(), words.end(), by length);
            sort(words.begin(),words.end(),[](string &a,string &b){
                return a.size()<b.size();
            });

            vector<int>dp(n,1);//dp[i] = longest chain ending at words[i]
            int maxLen=1;


            for(int i=1;i<n;i++)
            {
                for(int j=0;j<i;j++)
                {//Har word ke liye previous sab words check karo:
                    if(isPredecessor(words[j],words[i]) && dp[j]+1>dp[i])
                    {
                        //agar words[j] → words[i] valid chain hai
//to chain extend karo
                        dp[i]=dp[j]+1;
                    }
                }
                maxLen=max(maxLen,dp[i]);//maximum track karo
            }
            return maxLen;//answer return karo

        }
    
};