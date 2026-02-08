class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> freq;
        for(char t:tasks)
        {
           freq[t]++;
        }
        priority_queue<int>pq;
        for(auto &it:freq)
        {
            pq.push(it.second);//heap me isliye daal rhe hai kuki jada wala upr rhe
        }
         int time=0;
         while(!pq.empty())
         {
            //["A","B","C","D"]
            int cycle=n+1;//n hop gya 3
            vector<int>temp;
            //temp isliye liya hai taaki ek hi cycle me same task dobara execute na ho
            while(cycle-- >0 && !pq.empty())
            {
                //cycle-- > 0
//→ pehle compare, phir cycle decrement
                ///cyc--3
                ///elem A

                int curr=pq.top();
                pq.pop();
                if(curr-1>0)
                {
                    temp.push_back(curr-1);
                    
                }
                time++;
            }

            //bche hue jo is cycle me execute nhi hue unhe vaapis se heap me daalo
            for(int i:temp)
            {
                pq.push(i);
            }

            //ye na automatically ek add krega 
            //ya idle use krega
            if(!pq.empty())
            {
                time+=cycle+1;
            }
         }

         //end me time return
         return time;


    }
};