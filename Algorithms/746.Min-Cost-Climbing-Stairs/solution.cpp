class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(),0);
        int dp1 = cost[0];
        int dp2 = cost[1];
        int cur;
        for(int i=2;i<cost.size();i++){
           cur = min(dp1,dp2) + cost[i];
            dp1 = dp2;
            dp2 = cur;
        }
        
        return min(dp1,dp2);
    }
};
