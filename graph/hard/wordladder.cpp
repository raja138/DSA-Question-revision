//jo question maine smjha vo ye tha ki hme words diye hue hai 
//begiunword aur endword aur ek wordlist
//hme beginword se start krke endword tk jana hai
//aur ye dekhna hai ki minimum kitne transformation me hm end tk phuch skte hai
//return kro length of that array of words
//aur agr end word tk nhi phuch skte to return 0

//me initially kya soch rha tha ki saare words jha se shuru ho begin word se 
//end word tk ek word ek node bna lo aur phr edge bna lo ek word se dusre word tk jaane k liye
//aur bfs me nhi soch paaya tha ki shortest path bfs se nikal lo

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;

        int L = beginWord.size();

        // pattern -> list of words
        unordered_map<string, vector<string>> mp;
        mp.reserve(wordList.size() * L);

        for (auto &w : wordList) {
            for (int i = 0; i < L; i++) {
                string pat = w;
                pat[i] = '*';
                mp[pat].push_back(w);
            }
        }

        queue<pair<string,int>> q;
        unordered_set<string> vis;
        q.push({beginWord, 1});
        vis.insert(beginWord);

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