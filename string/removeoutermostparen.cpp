//are yrr ye question me bs bahar waali parenthesis hta do jo andar bche use rkh lena
//Input: s = "(()())(())"
//Output: "()()()"
///depth lenge aur result 
//logic--
//check krenge opening bracket hai aur agar depth greater than 0 hai result me char add kr denge
//else block me check krenge pehle depth -- krenge phr  kya closing bracket hai depth >0 to result me add kr denge

class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int depth = 0;
        
        for (char c : s) {
            if (c == '(') {
                if (depth > 0) {
                    result += c;
                }
                depth++;
            } else { 
                depth--;
                if (depth > 0) {
                    result += c;
                }
            }
        }
        
        return result;
    }
};