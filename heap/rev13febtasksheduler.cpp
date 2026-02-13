//code without comment
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>freq;
        priority_queue<int>pq;
        for(char c:tasks)
        {
            freq[c]++;
        }
        for(auto &t:freq)
        {
            pq.push(t.second);
        }
        int time=0;
        while(!pq.empty())
        {
            vector<int>temp;
            int cycle=n+1;
            while(cycle-->0 && !pq.empty())
            {
                int curr=pq.top();
                pq.pop();
                if(curr-->1)//yha pe maine cycle le li thi
                {
                    temp.push_back(curr);
                }
                time+=1;
            }
            for(int i:temp)
            {
                pq.push(i);
            }
            if(!pq.empty())
            {
                time+=cycle+1;//ise smjhna hai ki 
                //agar us cycle me jgh khaali hai 
                //aur koi element nhi aa skte to ye idle add kr deta hai 
                //edge case
            }
        }
        return time;
    }
};