//logic-
//map me frequency store kr lo
//map pe iterate kro aur vector me ka ek pair lekr frequncy wise sort kr lo


class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>freq;
        for(auto c:s)
        {
            freq[c]++;
        }

        //vector → dynamic array
//<pair<char,int>> → हर element एक pair होगा
//char = character (जैसे 'a')
//int = उसकी frequency (जैसे 3)
//यह एक ऐसा vector है जिसमें items ऐसे होंगे:
// ('a',3)
// ('b',1)
// ('c',5)
//(freq.begin(), freq.end())
//यह constructor है।
//अगर freq एक map<char,int> है, तो:
//freq.begin() → map का first element
//freq.end() → map का last के बाद वाला iterator
//👉 इसका मतलब:
//map के सारे elements copy करके vector में डाल दो
//तो अगर map में था:
//a → 2
//b → 1
//c → 3
//तो vec बन जाएगा:
//[('a',2), ('b',1), ('c',3)]
        vector<pair<char,int>>vec(freq.begin(),freq.end());

        sort(vec.begin(), vec.end(), [](auto &a, auto &b)
{
    return a.second > b.second;
});

// अब इसे धीरे-धीरे समझते हैं 👇
// 1️⃣ sort(vec.begin(), vec.end(), ...)
// vec.begin() → vector की शुरुआत
// vec.end() → vector का अंत
// मतलब: पूरा vector sort करो
// 2️⃣ [](auto &a, auto &b)
// यह lambda function है (custom comparator)
// []
// capture list (अभी empty है)
// (auto &a, auto &b)
// a = पहला element (pair)
// b = दूसरा element (pair)
// auto = compiler खुद type समझ लेगा
// (असल में type है: pair<char,int>)
// 3️⃣ return a.second > b.second;
// अब असली logic यहाँ है 🔥
// याद करो pair में:
// a.first → character
// a.second → frequency
// तो:
// a.second > b.second
// मतलब:
// 👉 जिसकी frequency ज्यादा हो वो पहले आए
// इसलिए sorting descending order में होगी।


        sort(vec.begin(),vec.end(),[](auto &a,auto&b)
        {
             return a.second>b.second;
        });
        string res="";
        for(auto &p:vec)
        {
            res.append(p.second,p.first);
        }

        return res;
    }
};