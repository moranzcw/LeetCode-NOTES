class Solution {
public:
    int distinctSubseqII(string S) {
        vector<long> endsWith(26,0);
        long mod = 1e9 + 7;
        for (auto c : S)
            endsWith[c - 'a'] = accumulate(begin(endsWith), end(endsWith), 1L) % mod;
        return accumulate(begin(endsWith), end(endsWith), 0L) % mod;  
    }
};
