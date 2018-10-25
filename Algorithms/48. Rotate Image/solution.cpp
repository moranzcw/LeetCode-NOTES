class Solution 
{
public:
    void rotate(vector<vector<int> > &matrix) 
    {
        int n=matrix.size();
        int temp = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
                swap(matrix[i][j],matrix[j][i]);
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};