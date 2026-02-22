//Question kya bol raha hai?

// Tumhe ek string s di hogi
// Us string me:

// '('

// ')'

// numbers

// operators (+ - * /)

// ho sakte hain.

// Tumhe sirf ye batana hai 👇
// 👉 maximum kitni parentheses ek sath open hui hain

class Solution {
public:
    int maxDepth(string s) {
        
        int res=0,cur=0;

        //'(' → andar ja rahe hain → count badhao
// ')' → bahar aa rahe hain → count ghatao
// Har step pe max yaad rakho
        for(char& c:s)
        {
            if(c=='('){
                cur++;
                res=max(res,cur);
            }
            if(c==')') {
                cur--;
            }
        }

        return res;
    }
};