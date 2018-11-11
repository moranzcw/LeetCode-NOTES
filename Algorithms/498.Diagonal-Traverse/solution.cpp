class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = row>0?matrix[0].size():0;
        vector<int> result(row*col,0);
        int cur = 0;
        bool right = false;
        int i,j,minn,start;
        for(int sum = 0;sum<row + col - 1;sum++){
            if(right){
                minn = min(row,sum+1);
                start = max(sum-col+1,0);
                for(i=start;i<minn;i++){
                    result[cur] = matrix[i][sum-i];
                    cur++;
                }
            }else{
                minn = min(col,sum+1);
                start = max(sum-row+1,0);
                for(j=start;j<minn;j++){
                    result[cur] = matrix[sum-j][j];
                    cur++;
                }
            }
            right = !right;
        }
        return result;
    }
};
