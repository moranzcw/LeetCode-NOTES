class Solution 
{
public:
    int minimumTotal(vector<vector<int> > &triangle) 
    {
            vector< vector<int> >::size_type length = triangle.size();
            if(length == 0){
                return 0;
            }
            int i, j;
            for(i=1;i<length;i++)
            {
                vector<int>::size_type length_inner = triangle[i].size();
                for(j=0;j<length_inner;j++)
                {
                    if(j == 0)
                    {
                        triangle[i][j] = triangle[i][j] + triangle[i-1][j];
                    }
                    else if(j == length_inner - 1)
                    {
                        triangle[i][j] = triangle[i][j] + triangle[i-1][j-1];
                    }
                    else
                    {
                        triangle[i][j] = (triangle[i][j] + triangle[i-1][j-1] < triangle[i][j] + triangle[i-1][j] ? triangle[i][j] + triangle[i-1][j-1]:triangle[i][j] + triangle[i-1][j]);
                    }
                }
            }
            int min_path = triangle[length-1][0];
            for(i=1;i<triangle[length-1].size();i++)
            {
                min_path = (min_path < triangle[length-1][i]?min_path:triangle[length-1][i]);
            }
            return min_path;
    }
};
