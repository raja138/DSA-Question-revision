class Solution {
public:
//k digits remove karne ke baad jo sabse chhota number ban sakta hai, 
//wahi string form mein return karo
//Socho number ko left se right:
//Agar koi digit apne right wale se bada hai
//to hta do
//num = 1 4 3

//1 < 4 → ok
//4 > 3 → ❌
//13

//to contradict above
//agr 3 htaye to 
//14 bnega

//to usko hata dena number ko chhota bana deta hai
    string removeKdigits(string num, int k) {
        stack<char>st;


//num = "1432219", k = 3

        //basically isme kya kr rhe hai ki poori string me iterate aur 
        //agar jaise hi right se left jaate waqt koi mil gya to use pop kr ke hta de rhe 
        //bche hue element ko reverse kr ke response me push kr denge
        for(char c:num)
        {
            //1---->c me aya 1 
            //2--->c me gya 4
            //2-->>>k-3
            //2--->>st.top()-->>>['4']
            //3-->>k=2
            //3 stack me-['1','4']
            //3-->>c--->3

            //2--->st.top jo hai vo ['1'] c tha 4 ye condition break st.top()>c 
            //3 -->st.top jo hai vo ['4'] c tha 3 ye condition satisfy st.top()>c  4>3
            while(!st.empty() && k>0 &&st.top()>c)
            {
                //3 me andar aa gya pop kiya 4 ko
                st.pop();
                //k ki value km kr di kuki best element remove  ho gya hai
                k--;
            }
            //1-->>stack me ['1']<-----top
            //2 -->>stack me gya 4
            //2--->>stack ho gya['1','4']<------top
            //3-->>stack me push []
            st.push(c);
        }
        
        //ye while ku zarori h 

        //aisa bhi ho skta hai ki tmhe koi upr ki condition satisfy kene wala mile hi nhi
        //aur k tmara vaise hi hai km nhi hua
        //num = "12345"
         //k = 2
        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }


        //ab aya mauka response bnane ka 
        //tmare stack me ab element hai htane k bd jo bche hai
        //unhe response me push kro
        string res;
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }

        //kuki stack me ulti string thi to ab tmhe seedhi krni hai
        reverse(res.begin(),res.end());

        //num = "10200"
        //k = 1
        //remove '1' → "0200"
        int idx=0;
        while(idx<res.size() &&res[idx]=='0') idx++;
        res=res.substr(idx);
         
         //agar res empty hai to  0 return kr do
        return res.empty()?"0":res;
    }
};