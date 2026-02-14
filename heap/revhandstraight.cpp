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
        for(auto&p:freq)
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
                    if(pq.top()!=curr) return false;
                    pq.pop();
                    freq.erase(curr);
                }
            }
        }
        return true;
    }
};