// Link : https://leetcode.com/problems/longest-happy-prefix/

class Solution {
    vector<int> prefixFunction(string s) {
        int n = s.length();
        vector<int> lps(n); // lps[0] -> 0
        for(int i = 1; i < n; ++i) {
            int j = lps[i-1]; // best scenario
            // s.charAt(j) == s.charAt(i) -> Scenario good to go.

            while(j > 0 && s[j] != s[i]) // O(N) times in total
                j = lps[j-1]; // s[0 .... j - 1]
            
            if(s[j] == s[i])
                j += 1;
            lps[i] = j;
        }
        return lps;
    }
public:
    string longestPrefix(string s) {
        int len = prefixFunction(s).back();
        return s.substr(0, len);
    }
};