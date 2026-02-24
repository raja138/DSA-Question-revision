//dierected aur undirected graph ko p[ehchante kaise hai
//Prerequisite:
//“To take course A, you must first take B.”
//This means:
//B → A
//But does A → B?
//No.
//So edge is one-directional.
//That is Directed Graph.

//If I reverse the edge,
//Does the meaning change?
//If yes → Directed
//If no → Undirected

//Cycle Detection – Directed Graph

//1)
//DFS + Recursion Stack
// Use 3 states:
// 0 → unvisited
// 1 → visiting (in recursion stack)
// 2 → visited (safe)
// If during DFS you reach a node with state = 1
// 👉 Cycle detected.
// This is the most intuitive for interview.
// Time: O(V + E)


//2)
//Kahn’s Algorithm (Topological Sort – BFS)
//Compute indegree
//Push nodes with indegree 0
//Process
//Count processed nodes
//If processed nodes < total nodes
//👉 Cycle exists.
//Why?
//Because cycle nodes never get indegree 0.


class Solution {
public:
    bool canFinish(int numCourses, const std::vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<int> indegree(numCourses, 0);
    
   
    for (const auto& p : prerequisites) {
        int course = p[0];
        int prereq = p[1];
        adj[prereq].push_back(course);
        indegree[course]++;
    }


  queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }


    int completed = 0;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        completed++;

        for (int neighbor : adj[curr]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }


    return completed == numCourses;
}
};