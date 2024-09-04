// Link : https://leetcode.com/problems/longest-duplicate-substring/

int p = 31, m1 = 1000000007, m2 = 998244353;

class Solution {
    long long getHash(string s, int mod) {
        long long ans = 0;
        for(int i = 0; i < s.length(); ++i) {
            int chInt = (s[i] - 'a');
            ans = (ans * p + chInt) % mod;
        }
        return ans;
    }

    long long powMod(int exp, int mod) {
        if(exp == 0)
            return 1;
        long long part = powMod(exp/2, mod);
        part = (part * part) % mod;

        return (exp&1) == 0? part : (part * p) % mod;
    }

    string getDuplicated(string &s, int len) {
        set<int> hashes1, hashes2;
        long long h1 = getHash(s.substr(0,len), m1);
        long long h2 = getHash(s.substr(0,len), m2);

        hashes1.insert(h1), hashes2.insert(h2);

        long long pPow1 = powMod(len - 1, m1), pPow2 = powMod(len - 1, m2);
        for(int i = len; i < s.length(); ++i) {
            // Slide the hash
            int delId = i - len;
            int delInt = s[delId] - 'a';

            // Get rid of s[delId]
            h1 = (h1 - pPow1 * delInt) % m1, h2 = (h2 - pPow2 * delInt) % m2;
            h1 = (h1 + m1) % m1, h2 = (h2 + m2) % m2;

            // Add s[i] to the hashes
            int addInt = s[i] - 'a';
            h1 = (h1 * p + addInt) % m1;
            h2 = (h2 * p + addInt) % m2;

            if(hashes1.count(h1) && hashes2.count(h2))
                return s.substr(i - len + 1, len);
            hashes1.insert(h1);
            hashes2.insert(h2);
        }
        return "";
    }
public:
    string longestDupSubstring(string s) {
        int beg = 1, end = s.length() - 1;
        string ans = "";
        while(beg <= end) {
            int mid = (beg + end)/2;
            string dup = getDuplicated(s, mid);
            if(dup.length()) {
                ans = dup, beg = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return ans;
    }