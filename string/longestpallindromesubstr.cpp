//ye ek br dekh lena


class Solution {
public:
    // expand around center [l, r] and return length + update best
    void expand(const string &s, int l, int r, int &bestL, int &bestLen) {
        int n = (int)s.size();
        while (l >= 0 && r < n && s[l] == s[r]) {
            l--;
            r++;
        }
        // palindrome is now (l+1) to (r-1)
        int len = r - l - 1;
        int start = l + 1;
        if (len > bestLen) {
            bestLen = len;
            bestL = start;
        }
    }

    string longestPalindrome(string s) {
        int n = (int)s.size();
        if (n <= 1) return s;

        int bestL = 0, bestLen = 1;

        for (int i = 0; i < n; i++) {
            // odd length center at i
            expand(s, i, i, bestL, bestLen);
            // even length center between i and i+1
            expand(s, i, i + 1, bestL, bestLen);
        }

        return s.substr(bestL, bestLen);
    }
};