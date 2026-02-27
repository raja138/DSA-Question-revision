//bipartite ka mtlb seedha ye hota hai 
//ki padosi ko same rang se color nhi karna hai
//aur node ka edge usi pe na ho
//dfs se krenge
//ek color ka vector lekr aur queue ka use kr k



class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
         int n = graph.size();
        vector<int> color(n, -1); 

        for (int start = 0; start < n; start++) {//hum hr node ko dekh rhe hai
            if (color[start] != -1) continue; //pehle se ranga hua hai to chor donge
            queue<int> q;
            q.push(start);
            color[start] = 0;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : graph[u]) {//pdosi ko dekhte hai
                    if (v == u) return false;//agar koi node khud se juda ho
                    //agar ye khud se conected ho to bipartite nhi hai
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    } else {
                        if (color[v] == color[u]) return false;
                    }
                }
            }
        }

        return true;
    
    }
};