// सबसे पहले, हम सारे शब्दों का सेट बनाते हैं 
// ताकि जल्दी चेक कर सकें। फिर हर शब्द के पैटर्न बनाते 
// हैं—एक अक्षर हटाकर स्टार लगाते हैं, ताकि हम पड़ोसी शब्द जल्दी पा सकें। 
// फिर हम हर शब्द का पिछला शब्द (parent) याद रखने के लिए एक मैप रखते हैं। 
// उसके बाद, हम एक क्व में शब्दों को लेवल के साथ डालते हैं और विज़िटेड शब्दों का 
// हिसाब रखते हैं। हर लेवल पर, हम सारे पड़ोसी शब्द देखते हैं और उस लेवल के नए शब्दों को जोड़ते हैं। 
// जब हम एंड वर्ड तक पहुंचते हैं, तब भी हम उस पूरे लेवल को पूरा करते हैं। उसके बाद, हम पीछे जाकर सारे 
// छोटे रास्ते बनाते हैं। आखिर में, ये छोटे-छोटे रास्ते ही हमारा नतीजा होते हैं। यही मुख्य बदलाव है—अब हम सिर्फ 
// लंबाई नहीं, बल्कि सभी छोटे रास्ते वापस देते हैं।

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
           unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> ans;
        if (!dict.count(endWord)) return ans;

        int L = beginWord.size();

        // pattern -> list of words (neighbors lookup fast)
        unordered_map<string, vector<string>> mp;
        mp.reserve(wordList.size() * L);

        for (auto &w : wordList) {
            for (int i = 0; i < L; i++) {
                string pat = w;
                pat[i] = '*';
                mp[pat].push_back(w);
            }
        }
        // beginWord wordList me na ho to bhi neighbors mil sake, iske patterns bhi add kar do
        for (int i = 0; i < L; i++) {
            string pat = beginWord;
            pat[i] = '*';
            mp[pat].push_back(beginWord);
        }

        // parents[child] = list of previous words that reach child in shortest way
        unordered_map<string, vector<string>> parents;
        parents.reserve(wordList.size() * 2);

        queue<string> q;
        q.push(beginWord);

        unordered_set<string> visited;          // globally visited after each level
        visited.insert(beginWord);

        bool found = false;

        while (!q.empty() && !found) {
            int sz = q.size();
            unordered_set<string> levelVisited; // words discovered in this level

            for (int k = 0; k < sz; k++) {
                string word = q.front();
                q.pop();

                for (int i = 0; i < L; i++) {
                    string pat = word;
                    pat[i] = '*';

                    auto it = mp.find(pat);
                    if (it == mp.end()) continue;

                    for (auto &next : it->second) {
                        if (next == word) continue;

                        // IMPORTANT: allow multiple parents in same level
                        if (!visited.count(next)) {
                            if (!levelVisited.count(next)) {
                                levelVisited.insert(next);
                                q.push(next);
                            }
                            parents[next].push_back(word);
                            if (next == endWord) found = true;
                        }
                    }
                }
            }

            // level complete => now mark them visited
            for (auto &w : levelVisited) visited.insert(w);
        }

        if (!found) return ans;

        // backtrack from endWord to beginWord using parents
        vector<string> path;
        path.push_back(endWord);

        function<void(const string&)> dfs = [&](const string& cur) {
            if (cur == beginWord) {
                vector<string> seq = path;
                reverse(seq.begin(), seq.end());
                ans.push_back(seq);
                return;
            }
            auto it = parents.find(cur);
            if (it == parents.end()) return;

            for (const string &p : it->second) {
                path.push_back(p);
                dfs(p);
                path.pop_back();
            }
        };

        dfs(endWord);
        return ans;
    }
};