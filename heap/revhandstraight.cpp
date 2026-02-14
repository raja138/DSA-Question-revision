//date- 14/feb/2026



//pehle to vo video dekh lena 
//https://www.youtube.com/watch?v=FyRdNhOqxY0

//usne kya smjhaya hai ki
//pehle frequency unordered map me store kra lenge
//phr ek ek krke uspe kaam krenge
//ek queue lenge to ek hands bnane me jitne use hue hai
//unko use krne k baad frequency me jo bchi hui hogi pehle queue me push phr vaapis se updated freq k sth unordered map me push



class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0) return false;
        //frequency k liye unordered map
        unordered_map<int,int> freq;
        for(int card:hand)
        {
            freq[card]++;
        }
        priority_queue<int,vector<int>,greater<int>>pq;//min heap
        //ye syntax smjh lo
        //min heap ka
        //priority_queue<datatype> name;
        //priority_queue<int> pq;
        //priority_queue<
    //int,           // 1. kis type ka data store hoga
    //vector<int>,   // 2. kis container me store hoga
    //greater<int>   // 3. kis rule se ordering hogi
//>
        for(auto &p:freq)
        {
            pq.push(p.first);
        }
        while(!pq.empty())
        {
            int start=pq.top();
            for(int i=0;i<groupSize;i++)
            {
                int curr=start+i;
                if(freq.find(curr)==freq.end())
                {
                    return false;
                }
                freq[curr]--;
                if(freq[curr]==0)
                {
                    //ye wala case dekh lena
                    //smjh gya upr check kr rhe hai 
                    //ki next element exist krta hai ya nhi
                    //ab maan lo next element ki 
                    //freq 0 ho gyi
                    //aur vo top me nhi hai
                    //to iska mtlb koi aur element hai
                    //pr hona to isiko chahiye
                    //taaki hm pop kr ske
                    //aur ye smalles element hona chahiye 

                    // curr ki freq 0 hone ka matlab curr fully use ho gaya.
// Ab curr heap ka smallest unused element hona chahiye.
// Agar pq.top() curr nahi hai, matlab koi smaller element abhi bhi bacha hai,
// jo consecutive order ko break karta hai.
// Isliye false return karte hain.

                    if(curr!=pq.top()) return false;
                    pq.pop();
                    freq.erase(curr);//map se bhi hta do
                }
            }
        }
        return true;
    }
};

//note--revision k liye 
//jb code implement kr rha tha to ek question tha ki bhai ye curr to start + i 
//to ye start kb pop ho rha to
//bhai start jha se start ho rha hai vo 0 se start ho rha hai
//to hmesha ek km rhega
//apne aap pop ho jayega