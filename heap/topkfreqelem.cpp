// Question kya keh raha hai?
// Tumhe diya hai:
// nums = [1,1,1,2,2,3]
// k = 2
// Tumhe return karna hai:
// k most frequent elements
// 🧠 Step 1: Frequency count karo
// Count karo har number kitni baar aaya:
// 1 → 3 times
// 2 → 2 times
// 3 → 1 time
// 🧠 Step 2: Top k frequent elements return karo
// Here:
// k = 2
// Top 2 frequent:
// 1 and 2
// Answer:
// [1,2]
// Order matter nahi karta:



class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        //question observe kro 
        //Tumhe chahiye:
        //Top 2 frequent elements
        //To sabse pehle pata hona chahiye:
        //kis element ki frequency kitni 
        
        //to frequency count ho jaygei freq me
        unordered_map<int,int>freq;
        for(int num:nums)
        {
            freq[num]++;
        }

        //freq = {
        //  1 → 3
        //  2 → 2
        //  3 → 1
         // }

         //ab tmare paas numbe hai unki freq hai
        //ab heap use ho jayega 
        //min heap of size k
        //now heap stores freq and number
        //push into heap
         //if heap size > k
         //pop smallest frequency
          //Why?
         //Because we only want:
          //top k largest frequencies

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        for(auto &it:freq)
        {
            //yha pe frequency k base maan k upr rkh rhe hai ku ki top k frequent element chahiye element
            pq.push({it.second,it.first});

            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        vector<int>result;
        while(!pq.empty())
        {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};