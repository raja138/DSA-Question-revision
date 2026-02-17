/*
QUESTION UNDERSTANDING (Number of Provinces)

- Hume n cities diye gaye hain.
- isConnected[i][j] = 1 ka matlab city i aur city j directly connected hain.
- Agar city A → B connected hai aur B → C connected hai,
  to A aur C indirectly connected hain.
- Province ka matlab hota hai:
  Ek group of cities jo direct ya indirect connection se connected ho.
- Hume total number of aise groups (provinces) find karne hain.
Example:
isConnected =
[
 [1,1,0],
 [1,1,0],
 [0,0,1]
]
Graph form me:
0 ---- 1
2
Yaha:
Province 1 = {0,1}
Province 2 = {2}
Answer = 2
CORE IDEA:
- Ye basically graph ka question hai.
- Har city ek node hai.
- isConnected matrix adjacency matrix hai.
- Hume number of connected components find karne hain.
APPROACH THINKING:
- Ek visited array banayenge taaki pata chale kaunsi city already visit ho chuki hai.
- Har city check karenge:
    agar visit nahi hui → new province mila
    fir DFS/BFS se us city se connected sab cities visit kar lenge.
- Jitni baar DFS start hoga utni provinces hongi.
SHORT MEMORY TRICK:
Number of Provinces = Number of Connected Components in Graph
*/

// Sabse pehle pattern identify karo
// Given:
// n cities
// connection matrix diya hai
// direct + indirect connections allowed
// groups count karne hain
// 👉 Ye clearly connected components in graph hai.


//Graph ko kaise represent karein?
// Matrix already given hai:
// isConnected[i][j] = 1 → edge between i and j
// So hume adjacency list banane ki bhi zarurat nahi hai.
// Matrix se hi traverse kar sakte hain.

// Main intuition
// Socho tum cities visit kar rahe ho.
// Rule:
// Agar koi city abhi tak visit nahi hui → new province mila
// Fir us city se connected sab cities visit kar lo (DFS/BFS)


class Solution {
public:
    void dfs(int city,vector<vector<int>>& isConnected,vector<int>& visited) {

        // DFS ka kaam hai current city se connected sab cities ko visit karna
// visited mark isliye karte hain taaki same city dobara visit na ho
// agar isConnected[city][j] == 1 and visited[j] == 0
// matlab j same province ka part hai
// recursive DFS se pura connected component visit ho jata hai
            // Step 1: current city ko visited mark karo
    // iska matlab ye city ab kisi province me include ho chuki hai
        visited[city]=1;
         // Step 2: ab check karo kaunsi cities current city se connected hain
    // isConnected matrix me row = city
    // aur column = possible neighbour cities
        for(int j=0;j<isConnected.size();j++)
        {
            // // agar current city aur j connected hain
        // aur j abhi tak visit nahi hui hai
            if(isConnected[city][j]==1 && !visited[j])
            {
                 // to j bhi same province ka part hai
            // isliye us par DFS call karenge
                dfs(j,isConnected,visited);
            }

        }
    }

    int findCircleNum(vector<vector<int>>& isConnected)
    {
        // // isConnected ek adjacency matrix hai
    // size n ka matlab total n cities hain
        int n=isConnected.size();

         // visited array use kar rahe hain ye track karne ke liye
    // kaunsi city already kisi province me include ho chuki hai
    // 0 = not visited
    // 1 = visited
        vector<int> visited(n,0);

        // provinces count store karega
    // har baar jab ek new unvisited city milegi → new province milega
        int provinces=0;

//// sab cities ko check karenge
        for(int i=0;i<n;i++)
        {
            //// agar current city abhi tak visit nahi hui
        // iska matlab ye kisi naye province ka start ho sakta hai
            if(!visited[i])
            {
                //// new province mila
                provinces++;

                // DFS call karke current city se connected
            // saari cities ko visited mark kar denge
            // taaki unhe dobara province count na karein
                dfs(i,isConnected,visited);
            }
        }

        // total provinces return karenge
        return provinces;
    }


};