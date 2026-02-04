class Solution {
public:
//“Asteroids ek line mein move kar rahe hain.
//Jab right-moving asteroid left-moving se takrata hai,
//toh chhota destroy hota hai.
//Hume final survivors batane hain.”


// Case-1
// Box wala chhota
// box se nikaal do
// current asteroid abhi zinda
// next box wale se phir takrao
// Case-2
// Dono barabar
// box wala bhi gaya
// current bhi gaya
// yahin ruk jao
// Case-3️
// Box wala bada
// current asteroid toot gaya
// box wahi ka wahi
// yahin ruk jao


    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;//box asteroid rkhne k liye
        for(int a:asteroids)//iterate over asteroid
        {
            bool destroyed=false;//current element
            //
            while(!st.empty() && st.top()>0 && a<0)//iske andar hm tbhi laa rhe jb a negative ho aur +ve se compare kr le 
            {
              if(abs(st.top())<abs(a))//stack wala destroy ho gya kuki chota tha
              {
                st.pop();//pop mtlb stack wala destroyed
                continue;//ye continue kya krega yha ki kuki stack wala asteroid destroy ho gya to while loop phr se chlayega aur agle stack k top se compare krega
              }
              else if(abs(st.top())==abs(a))//agar dono element brarbr h to desroy kr do yha stack waale ko niche a waale asteroid ko
              {
                st.pop();
              }
              destroyed=true;
              break;//while loop tod dega aur next a pe jayega
            }
            //ye condition +ve aur negative dono ko push kra degi agar hoga aisa scene warna +ve ko hi krayegi
            if(!destroyed)
            {
                st.push(a);
            }
        }


        //abhi tk kaheen hmne answer nhi rkha hai 
        //to hm piche se answer push kr denge vector me
        vector<int> ans(st.size());
//hm ulta order nhi chahte hai seedha chahte hai isliye aisekr rhe hai
        for(int i=st.size()-1;i>=0;i--)
        {
            ans[i]=st.top();
            st.pop();
        }

        return ans;
    }
};