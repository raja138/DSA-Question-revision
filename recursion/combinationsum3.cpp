// We must choose k numbers from 1–9 such that their sum = n, and each number can be used only once.
// 🧠 Key Idea
// We try numbers from 1 to 9, and at every step we:
// Add a number
// Reduce the remaining sum=
// Continue recursion with the next number
// Backtrack
// Constraints:
// Only numbers 1 → 9
// Exactly k numbers
// Total sum = n
// 🔁 Recursive Thinking
// At each step we decide:
// take number i
// or move to next number
// Stop recursion when:
// current.size() == k
// If sum becomes 0 → valid combination.

class Solution {
public:
    
    void solve(int start, int k, int target, vector<int>& current, vector<vector<int>>& result)
    {
        if(target == 0 && current.size() == k)
        {
            result.push_back(current);
            return;
        }
        
        if(target < 0 || current.size() > k)
            return;
        
        for(int i = start; i <= 9; i++)
        {
            current.push_back(i);
            
            solve(i + 1, k, target - i, current, result);
            
            current.pop_back(); // backtrack
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>> result;
        vector<int> current;
        
        solve(1, k, n, current, result);
        
        return result;
    }
};