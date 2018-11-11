class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        queue<pair<int,int> > que;
        
        bool found = false;
        for(int i=0;i<A.size();i++){
            for(int j=0;j<A[0].size();j++){
                if(A[i][j] == 1){
                    found = true;
                    dfs(A, i,j,que);
                    break;
                }
            }
            if(found)
                break;
        }
        
        int x,y,step=0;
        while(que.size() != 0){
            int size = que.size();
            for(int i=0;i<size;i++){
                x = que.front().first;
                y = que.front().second;
                que.pop();

                if(x-1>=0 && A[x-1][y] != 2){
                    if(A[x-1][y] == 0){
                        A[x-1][y] = 2;
                        que.push(pair<int,int>(x-1,y));
                    }else if(A[x-1][y] == 1){
                        return step;
                    }
                }
                if(x+1<A.size() && A[x+1][y] != 2){
                    if(A[x+1][y] == 0){
                        A[x+1][y] = 2;
                        que.push(pair<int,int>(x+1,y));
                    }else if(A[x+1][y] == 1){
                        return step;
                    }
                }
                if(y-1>=0 && A[x][y-1] != 2){
                    if(A[x][y-1] == 0){
                        A[x][y-1] = 2;
                        que.push(pair<int,int>(x,y-1));
                    }else if(A[x][y-1] == 1){
                        return step;
                    }
                }
                if(y+1<A[0].size() && A[x][y+1] != 2){
                    if(A[x][y+1] == 0){
                        A[x][y+1] = 2;
                        que.push(pair<int,int>(x,y+1));
                    }else if(A[x][y+1] == 1){
                        return step;
                    }
                }
            }
            step += 1;
        }
        return step;
    }
    
    int dfs(vector<vector<int>>& A, int x, int y, queue<pair<int,int> > & que){
        if(A[x][y] == 1){
            que.push(pair<int,int>(x,y));
            A[x][y] = 2;
            
            if(x-1>=0)
                dfs(A, x-1,y,que);
            if(x+1<A.size())
                dfs(A, x+1,y,que);
            if(y-1>=0)
                dfs(A, x,y-1,que);
            if(y+1<A[0].size())
                dfs(A, x,y+1,que);
        }
        
        return 0;
    }
};
