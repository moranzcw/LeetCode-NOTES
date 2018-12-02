class Solution {
public:
    int p[100100], sz[100100];
    
    int find(int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }
    
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) return;
        sz[x] += sz[y];
        p[y] = x;
    }
    
    int largestComponentSize(vector<int>& A) {
        bool mark[100100] = {0}, used[100100] = {0};
        for(int x : A) {
            mark[x] = 1;
            p[x] = x;
            sz[x] = 1;
        }
        // Sieve of erastosthenes
        for(long long i = 2; i <= 100000; i++) {
            if(!used[i]) {
                int last = -1;
                // i is a prime, union all numbers which has i as its factor.
                for(long long j = i; j <= 100000; j += i) {
                    used[j] = 1;
                    if(mark[j]) {
                        if(last != -1) merge(last, j);
                        last = j;
                    }
                }
            }
        }
        int ans = 0;
        for(int x : A) ans = max(ans, sz[x]);
        return ans;
    }
};
