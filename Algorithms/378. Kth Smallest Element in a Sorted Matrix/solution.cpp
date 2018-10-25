class Solution 
{
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        vector<int> vec(matrix.size()*matrix[0].size());
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix[0].size();j++)
                vec[i*matrix[0].size()+j]=matrix[i][j];
        sort(vec.begin(),vec.end());
        return vec[k-1];
    }
};