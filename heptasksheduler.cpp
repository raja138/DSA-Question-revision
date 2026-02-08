//Question kya keh raha hai?

// Tumhe:
// tasks diye gaye hain → har task ek capital letter (A–Z)
// har task ko 1 unit time lagta hai
// ek number n diya hai → cooldown time
// 🔥 Cooldown ka matlab
// Agar tumne same task execute kiya,
// toh usko dobara chalane se pehle kam se kam n time ka gap hona chahiye.
// 📌 Simple language me:
// Same type ka kaam baar-baar nahi kar sakte.
// Beech me ya to dusre task karo ya idle (kuch bhi mat karo).

// 📘 Example 1
// tasks = [A, A, A, B, B, B]
// n = 2
// Matlab:
// A ke baad 2 time gap
// B ke baad bhi 2 time gap
// ❌ Galat schedule
// A A B B A B   ❌
// Kyun?
// 👉 A ke beech gap nahi mila
// ✅ Sahi schedule
// A B idle A B idle A B
// A ke beech 2 gap ✔
// B ke beech 2 gap ✔
// ⏱ Total time = 8


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        //Problem me hume kya chahiye?
//Hume har task (A, B, C...) ka count chahiye.
//Example:
//tasks = [A, A, A, B, B, C]
//Hume ye pata hona chahiye:
//A → 3
//B → 2
//C → 1
//Kyun?
//👉 Kyunki jo task sabse zyada baar aata hai, wahi schedule ko control karta hai.

// 🔹 unordered_map<char,int> ka kaam
// unordered_map<char,int> freq;
// char → task name ('A' to 'Z')
// int → kitni baar aaya (frequency)
        unordered_map<char,int> freq;
        
        //map me chararacter ki frequency bhar rhe hai 
        for(char t:tasks)
        {
            freq[t]++;
        }

        priority_queue<int>pq;

        for(auto &it:freq)//<<<--ye refrence hai ku hai?-->>
// it = copy of element
// Agar freq ka element hai:
// pair<char, int>
// Toh har iteration me:
// ek naya pair copy hota hai
// Jab tum likhte ho:
// for (auto &it : freq)
// it = reference to original element
// Koi copy nahi banti
// Direct map ke element ko point karta hai
        {
            pq.push(it.second);
             //pq.push(it.second) kya kar raha hai?// 👉 Har character ki frequency ko heap (priority_queue) me daal raha hai
        }
       
        int time=0;
        //tasks = [A, A, A, B, B, B]--pq
         //n = 2

         //pq = [3, 3]
         //time = 0
        //Jab tak koi task pending hai
        while(!pq.empty())
        {
           //cycle = 3
           //cycle ka mtlb Ek round me max 3 different tasks
            int cycle=n+1;
            vector<int>temp;
            //Is cycle ke baad jo tasks bache honge, unko temporarily rakhne ke liye

            //cycle = 3 → >0 ✔
            //pq not empty ✔

            //2-->iteration
            cycle now = 2
// 🔹 Inner iteration 2
// cycle = 2 ✔
// pq not empty ✔
// curr = 3
// pq.pop();   // pq empty
// temp.push_back(2);
// temp = [2,2]
// time++;  // time = 2
// cycle now = 1
// 🔹 Inner iteration 3
// cycle = 1 ✔
// pq empty ❌
// ➡️ inner while STOP
            while(cycle-- >0 && !pq.empty())
            {
                int curr=pq.top();// curr = 3
                pq.pop();// pq = [3]
                if(curr-1>0)//curr=3
                {
                    temp.push_back(curr-1);

                    //curr=3 curr-1=2 temp = [2]
                }
                time++;
                // time = 1
            }
            //TEMP BACK TO HEAP
            //for(int i : temp)
            //pq.push(i);
            //pq = [2,2]
            //for (int i : temp) {
    //pq.push(i);
//}
// Jo tasks abhi bhi bache hue hain, unko next round (cycle) ke liye wapas heap me daalne ke liye
            for(int i:temp)
            {
                pq.push(i);
            }
            if(!pq.empty())
            {
                time+=cycle+1;
            }
        }
        //Ek task chalane me = 1 unit time
        //Ek idle slot me = 1 unit time
//time count karta hai:
        return time;
        
    }
};

//maine utube ki video dekhi aur seekha ki
//aise task ko execute krna hai ki time na lage jada
//do same task ko perform krne k liye hme
//ek unit ka cool down chahiye
//to agar sb different hai to array ki length me hi ho jayega execute
//to hm kya try krenge ki jis bhi task ki sbse jada frequency hai use pehle khtm kre
//kuki maan lo agar bhot task bch gya same wala to use khtm krne me bhot time lgega kuki idle time bhi add hoga
//





//https://www.youtube.com/watch?v=VGpamsI5hOM