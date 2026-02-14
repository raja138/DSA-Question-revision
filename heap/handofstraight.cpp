//Tumhare paas cards ka ek array hand hai.
//Har card pe number likha hai (jaise 1, 2, 3, 4…).
//Tumhe check karna hai:
//Kya in cards ko chhote-chhote groups me baanta ja sakta hai,
//jahan:
//Har group ka size groupSize ho
//Har group ke cards consecutive numbers ke ho
//(matlab lagataar numbers, jaise 3,4,5)
// Important baatein
//Har card sirf ek baar use ho sakta hai
//Groups ka order matter nahi karta
//Har group me numbers +1 ke gap se hone chahiye

//note-
// Saare cards ko use karke groups banana zaroori hai
// Matlab:
// Har card kisi na kisi group ka part hona chahiye
// Har group:
// size = groupSize
// consecutive numbers ka


class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
//Agar har group ka size groupSize hai, to:
//total cards ko exactly divide hona chahiye
//Agar:
//hand.size() % groupSize != 0
// Direct false
        int n=hand.size();
        if(n%groupSize !=0) return false;

        //Count kitni baar kaunsa card aaya
//Kyun?
//Kyuki duplicates ho sakte hain.
// Isliye:
//ek frequency map banate hain
//batata hai: kaunsa card kitni baar available hai
        unordered_map<int,int> freq;
        for(int card:hand)
        {
            freq[card]++;
            
        }

        //Hamesha sabse chhota card uthao

// Greedy idea (IMPORTANT):
// Jo sabse chhota card bacha hai, usi se group banana majboori hai
// Kyun?
// Usse chhota koi card bacha hi nahi
// Agar usse group start nahi kiya, to wo kabhi fit nahi hoga
// 👉 Iske liye:
// min heap (priority queue)
        priority_queue<int,vector<int>,greater<int>>pq;


        for(auto &p:freq)
        {
            pq.push(p.first);
        }
        while(!pq.empty())
        {
           int start=pq.top();
           for(int i=0;i<groupSize;i++)
            {
              int curr=start+i;//uska agla
              //Har card check karo
              //Group ke har card ke liye:
               //kya card exist karta hai?
               //❌ nahi → false
                //exist karta hai → frequency -1

                if(freq.find(curr)==freq.end())
                {
                    //agar nhi krta hai to return false
                    return false;
                }
                //krta hai to use kr liya freq--
                freq[curr]--;
                //agr vo element poori trh se use 
                 //ho chuka hai to 
                 //use heap se bhi nikal do
                if(freq[curr]==0)
                {
                    //lekin order matter karta hai
                    // Agar heap ke top pe wo card nahi hai → ❌ false
                    if(pq.top()!=curr) return false;
                    pq.pop();//heap se nikalo
                    freq.erase(curr);//erase kr do 
                }
            }
        }
        return true;
    }
};