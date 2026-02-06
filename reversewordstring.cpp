class Solution {

//Tumhe ek string s di hogi.
//Tumhe:
 //Words ka order reverse karna hai
//Extra spaces hataani hain
// Words ke beech sirf ek space rehni chahiye

public:
    string reverseWords(string s) {

        //Automatically:
        //Extra spaces ignore
        //Word-by-word read

        //s = "the sky is blue"
        stringstream ss(s);
        //words 
        //the␣sky␣is␣blue


        vector<string>words;

//         words → sab words store karega
// word → ek-ek word temporary hold karega


       //word pe iterate krne k liye
        string word;
//Stream se next word uthata hai
//space ko delimiter maanta hai
//multiple spaces ho → automatically ignore



        while(ss>>word)
        {
            //ss se word daalo
            words.push_back(word);
            //words k vector me push kro

            ////ss >> word  → "the"
            //words.push_back("the");
        }

        //words = {"the", "sky", "is", "blue"}

          //ab vector reverse kr do 
        reverse(words.begin(),words.end());


        //after reverse --kuki question me hi reverse hai
        ////words = {"the", "sky", "is", "blue"}

        string result="";
        for(int i=0;i<words.size();i++)
        {
            result+=words[i];//result h
            if(i!=words.size()-1)//hr words k bd space chahiye last k bd nhi
            {
                result += " ";//adding space
            }
        }
          
          //result me aa jayega "The sky is blue"


        return result;
    }
};