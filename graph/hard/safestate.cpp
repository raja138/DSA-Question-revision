//mon------>>23/02/2026

//mujhe contstraint pdhna nhi aataa
//maine socha tha vector pe iterate kro jo bhi
//graph ka array empty ho vo terminal node hogi
//ab us index ko graph me dhundo aur jisme bhi mile uski index ans me push kr do
//aur sort kr do
//issue in my code
// Only direct terminal neighbor check — safe states chain miss ho jaati.
// find() on vector inside loops → worst-case O(n^2)+ (slow).
// duplicates in ans (same node add multiple times), then sort only.
//agar cycle nikal bhi lu pr dusri node se cycle bn rhi hogi to nhi ho payega
// my code-
// class Solution {
// public:
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         vector<int>terminalNode;
//         vector<int>ans;
// for(int i=0;i<graph.size();i++)
// {
//     if(graph[i].size()==0)
//     {
//         terminalNode.push_back(i);
//     }
// }

// for(int i=0;i<graph.size();i++)
// {
//     if(graph[i].size()==0)
//     {
//         ans.push_back(i);
//     }
//  for(int j=0;j<graph[i].size();j++)
//  {
//     if (find(terminalNode.begin(), terminalNode.end(), graph[i][j]) != terminalNode.end()) 
//     {
//         ans.push_back(i);

//     }
//  }  
// }
// sort(ans.begin(),ans.end());
// return ans;        
//     }
// };


//Error notebook me kya likhna (short)
// Mistake: safe = direct terminal neighbor assume kiya
// Missing concept: cycle + safe propagation
// Correct pattern: reverse graph + outdegree reduction (Kahn / topo)
// Signal in question: “eventual” + “all paths” ⇒ cycle/terminal reachability problem


//ye hoga kaise??-
//Idea:
//Terminal nodes (outdegree 0) definitely safe.
//Reverse edges banao.
//Outdegree ko “remaining exits” ke tarah treat karo.
//Jo node ke saare exits safe ho jaate hain → wo bhi safe.
//Steps:
//outdegree[i] = graph[i].size()
//reverseGraph[v].push_back(i) for each edge i->v
//queue me sab terminal (outdegree 0)
//pop node u:
//u safe
//for each parent p in reverseGraph[u]:
//outdegree[p]--
//if outdegree[p]==0 push p
//Jo safe mark hue unko sort karke return.
//Why works: cycle nodes ka outdegree kabhi 0 nahi hota, so wo queue me aate hi nahi.


//correct code

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> rev(n);
        vector<int> outdeg(n, 0);
        for(int u = 0; u < n; u++){
            outdeg[u] = graph[u].size();
            for(int v : graph[u]){
                rev[v].push_back(u);
            }
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(outdeg[i] == 0) q.push(i); 
        }
        vector<int> safe(n, 0);
        while(!q.empty()){
            int u = q.front(); q.pop();
            safe[u] = 1;
            for(int p : rev[u]){
                outdeg[p]--;
                if(outdeg[p] == 0) q.push(p);
            }
        }
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(safe[i]) ans.push_back(i);
        }
        return ans;
    }
};