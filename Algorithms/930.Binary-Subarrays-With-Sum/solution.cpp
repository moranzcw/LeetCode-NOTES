class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        vector<int> dp(A.size()+1,0);
        
        map<int, vector<int> > mapp;
        
        dp[0] = 0;
        for(int i=0;i<A.size();i++){
            dp[i+1] = dp[i] + A[i];
            if(mapp.count(dp[i+1])>0)
                mapp[dp[i+1]].push_back(i);
            else
                mapp[dp[i+1]] = vector<int>(1,i);
        }
        
        
        int num = 0;
        for(int i=0;i<A.size();i++){
            int del = S + dp[i];
            if(mapp.count(del)>0){
                for(int j=0;j<mapp[del].size();j++)
                    if(mapp[del][j] >= i)
                        num += 1;
            }
            // for(int j=i;j<A.size();j++){
            //     if(dp[j+1] - dp[i] == S)
            //         num += 1;
            // }
        }
        return num;
    }
};
