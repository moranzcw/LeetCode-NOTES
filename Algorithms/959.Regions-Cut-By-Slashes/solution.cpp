class Solution {
public:
    void dfs(vector<vector<int>>& g, int i, int j) {
        if (i >= 0 && j >= 0 && i < g.size() && j < g.size() && g[i][j] == 0) {
            g[i][j] = 1;
            dfs(g, i-1, j);
            dfs(g, i+1, j);
            dfs(g, i, j-1);
            dfs(g, i, j+1);
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        int N = grid.size();
        vector<vector<int>> g(N*3, vector<int>(N*3, 0));
        for (int i=0; i<grid.size(); i++)
            for (int j=0; j<grid.size(); j++) {
                if (grid[i][j] == '/'){
                    g[i*3][j*3 + 2] = 1;
                    g[i*3 + 1][j*3 + 1] = 1;
                    g[i*3 + 2][j*3] = 1;
                }
                if (grid[i][j] == '\\'){
                    g[i*3][j * 3] = 1;
                    g[i*3 + 1][j*3 + 1] = 1;
                    g[i*3 + 2][j*3 + 2] = 1;
                }
        }
        int result = 0;
        for (int i=0; i<g.size(); i++){
            for (int j=0; j<g.size(); j++){
                if (g[i][j] == 0){
                    dfs(g, i, j);
                    result++;
                }
            }
        }
        return result;
    }
};
