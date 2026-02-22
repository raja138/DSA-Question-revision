class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string>v;
        string res="";
         string word;
           while(ss>>word)
           {
            v.push_back(word);
           }


           for(int i=v.size()-1;i>=0;i--)
           {
            res+=v[i];
            if(i>0)
            {
                res+=" ";
            }
           }

           return res;

    }
};