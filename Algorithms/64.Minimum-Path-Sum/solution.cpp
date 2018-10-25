class Solution 
{
public:
    int minPathSum(vector<vector<int> > &grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int> > DP(m, vector<int>(n));

        DP[0][0] = grid[0][0];
        for(int i = 1; i < n; i++)
            DP[0][i] = DP[0][i-1] + grid[0][i];
            
        for(int i = 1; i < m; i++)
            DP[i][0] = DP[i-1][0] + grid[i][0];
            
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                DP[i-1][j] < DP[i][j-1] ? DP[i][j] = DP[i-1][j] + grid[i][j] : DP[i][j] = DP[i][j-1] + grid[i][j];
                
        return DP[m-1][n-1];
    }
};