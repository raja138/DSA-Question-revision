// Kahn's Algorithm (Topological Sort using BFS)
// Hinglish comments: kya/kyu/kaise + kaha use hota hai

#include <bits/stdc++.h>
using namespace std;

/*
Kahn's Algorithm kya karta hai?
- Directed graph ka Topological Order nikalta hai (DAG ke liye).
- Agar topological order poora nikal paye (processed nodes == n) => cycle nahi hai
- Agar kuch nodes process hi nahi ho paaye (processed < n) => cycle present hai

Kaha use hota hai?
1) Course Schedule / Prerequisites (LeetCode 207, 210)
2) Dependency resolution: build systems, package managers (tasks with dependencies)
3) Scheduling problems: job scheduling with precedence constraints
4) Detecting cycle in directed graph (by processed count)
*/

vector<int> topoSortKahn(int n, const vector<vector<int>>& edges, bool &hasCycle) {
    // adj[u] me saare v store honge jinke liye u -> v edge hai
    vector<vector<int>> adj(n);

    // indeg[v] = v par kitni incoming edges aa rahi hain (kitne prerequisites)
    vector<int> indeg(n, 0);

    // 1) Edge list ko adjacency list me convert + indegree fill
    // edges format: {u, v} means u -> v
    for (auto &e : edges) {
        int u = e[0];
        int v = e[1];
        adj[u].push_back(v);
        indeg[v]++; // v ka indegree badha, kyunki u se v me edge aa rahi
    }

    // 2) Queue me wo nodes daalo jinka indegree 0 hai
    // (matlab: inke upar koi dependency nahi, ye start ho sakte hain)
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) q.push(i);
    }

    // 3) BFS style processing
    vector<int> order; 
    order.reserve(n);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // u ko topo order me add kar do
        order.push_back(u);

        // u ke neighbors (u -> v)
        for (int v : adj[u]) {
            // u process ho gaya, to v par se ek dependency remove
            indeg[v]--;

            // agar v ka indegree 0 ho gaya => ab v start ho sakta
            if (indeg[v] == 0) q.push(v);
        }
    }

    // 4) Cycle detection:
    // Agar n nodes process ho gaye => cycle nahi
    // Agar order size < n => kuch nodes kabhi indegree 0 nahi hue => cycle
    hasCycle = ((int)order.size() != n);

    return order; // DAG me valid topo order milega, cycle ho to incomplete order
}

/*
Course Schedule (LeetCode 207) me apply kaise karte hain?
Input prerequisites: [course, prereq]
Meaning: prereq -> course
To edges banane ke liye: edges.push_back({prereq, course});
*/
bool canFinishCourses(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> edges;
    edges.reserve(prerequisites.size());

    for (auto &p : prerequisites) {
        int course = p[0];
        int prereq = p[1];
        edges.push_back({prereq, course}); // prereq -> course
    }

    bool hasCycle = false;
    vector<int> order = topoSortKahn(numCourses, edges, hasCycle);

    // agar cycle hai => courses complete nahi ho sakte
    return !hasCycle;
}

// (Optional) Example run
int main() {
    int n = 4;
    vector<vector<int>> prerequisites = {{1,0},{2,1},{3,2}}; // 0->1->2->3

    cout << (canFinishCourses(n, prerequisites) ? "YES, can finish\n" : "NO, cycle present\n");

    // Topo order dekhna ho:
    vector<vector<int>> edges;
    for (auto &p : prerequisites) edges.push_back({p[1], p[0]});

    bool hasCycle = false;
    auto order = topoSortKahn(n, edges, hasCycle);

    if (!hasCycle) {
        cout << "Topo Order: ";
        for (int x : order) cout << x << " ";
        cout << "\n";
    } else {
        cout << "Cycle detected, topo order not possible.\n";
    }

    return 0;
}