//jo question maine smjha vo ye tha ki hme words diye hue hai 
//begiunword aur endword aur ek wordlist
//hme beginword se start krke endword tk jana hai
//aur ye dekhna hai ki minimum kitne transformation me hm end tk phuch skte hai
//return kro length of that array of words
//aur agr end word tk nhi phuch skte to return 0

//me initially kya soch rha tha ki saare words jha se shuru ho begin word se 
//end word tk ek word ek node bna lo aur phr edge bna lo ek word se dusre word tk jaane k liye
//aur bfs me nhi soch paaya tha ki shortest path bfs se nikal lo


//unweighted graph me bfs hi shortest path deta
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
         //हमने unordered set इसलिए लिया ताकि हम जल्दी से देख सकें कि कोई शब्द हमारी वर्ड लिस्ट में है या नहीं, क्योंकि 
         //unordered set में average lookup O(1) होता है। इस तरह से हम जल्दी से शब्द चेक कर पाते हैं
       

    //जब हम चेक करते हैं कि end word हमारी dictionary में है या नहीं, तो यह count zero मतलब end word मौजूद नहीं है। 
    //इसका मतलब है कि अगर हमारा end word शब्दकोश में ही नहीं है, तो हम कभी उस तक पहुँच नहीं पाएंगे। ऐसे में हम सीधे 0 रिटर्न कर देते हैं।
        if (!dict.count(endWord)) return 0;

        int L = beginWord.size();//saare word ki size same hai

        // pattern -> list of words
        unordered_map<string, vector<string>> mp;
        mp.reserve(wordList.size() * L);//pehle se hi unordered map k liye memory reserve kr lete hai
        //kuki hme pehle se hi idea hota hai ki kitna memory store krti hai


        //इस हिस्से में हम हर शब्द को ले रहे हैं, जो वर्ड लिस्ट में है। फिर हम उस शब्द के हर अक्षर को एक-एक करके बदल रहे हैं—उस जगह पर एक वाइल्डकार्ड, यानी स्टार (*) लगा रहे हैं। मतलब, हर अक्षर की जगह हम देखते हैं कि अगर उस अक्षर को हम हटा दें और उसकी जगह स्टार रखें, 
       //तो वो पैटर्न क्या बनेगा। फिर उस पैटर्न को हम मैप में जोड़ देते हैं, 
        //ताकि बाद में हमें पता रहे कि कौन-कौन से शब्द उस पैटर्न से मिलते हैं।
        for (auto &w : wordList) {
            for (int i = 0; i < L; i++) {
                string pat = w;
                pat[i] = '*';
                mp[pat].push_back(w);
            }
        }


        // यहाँ हम BFS यानी Breadth-First Search शुरू कर रहे हैं। 
        // हमने एक क्यू बनाया, जिसमें हर एंट्री में एक शब्द और उसका लेवल (या स्टेप नंबर) होगा। 
        //हम शुरुआत में क्यू में begin word और उसका लेवल (1) डालते हैं।
        // साथ ही, हम एक unordered set vis (visited) बनाते हैं, ताकि हम ट्रैक कर सकें 
        //कि कौन से शब्द हम पहले ही देख चुके हैं, ताकि हम उन्हें बार-बार प्रोसेस न करें। 
        // शुरू में हम begin word को visited में डाल देते हैं, ताकि हम उसे दोबारा प्रोसेस न करें।
        // इस तरह हम लेवल-बाय-लेवल शब्दों को आगे बढ़ाते हैं।
        queue<pair<string,int>> q;
        unordered_set<string> vis;
        q.push({beginWord, 1});
        vis.insert(beginWord);



//इस ब्लॉक में हम BFS चला रहे हैं। जब तक क्यू खाली नहीं हो जाता, हम हर शब्द को लेवल के साथ निकालते हैं। 
//अगर निकला हुआ शब्द एंड वर्ड है, तो हम उसी समय उसका लेवल (यानी स्टेप्स) रिटर्न कर देते हैं। 
//फिर हम हर अक्षर की जगह पैटर्न बनाते हैं, और उस पैटर्न से जुड़े अगले शब्द देखते हैं। जो शब्द पहले नहीं देखे गए, उन्हें हम क्यू में डाल देते हैं 
//अगले लेवल के साथ। एक बार जब हम किसी पैटर्न के सारे शब्द देख लेते हैं, तो हम उस पैटर्न को साफ कर देते हैं, ताकि हम दोबारा उसे प्रोसेस न करें।
        while (!q.empty()) {
            auto [word, level] = q.front();
            q.pop();

            if (word == endWord) return level;

            for (int i = 0; i < L; i++) {
                string pat = word;
                pat[i] = '*';

                auto it = mp.find(pat);
                if (it == mp.end()) continue;

                for (auto &next : it->second) {
                    if (!vis.count(next)) {
                        vis.insert(next);
                        q.push({next, level + 1});
                    }
                }

                // optimization: same pattern ko dobara process na karo
                it->second.clear();
            }
        }

        return 0;
    }
};