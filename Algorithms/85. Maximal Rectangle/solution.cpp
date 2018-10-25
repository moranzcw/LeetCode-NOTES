class Solution 
{
public:
    bool** rectangle;
    int maximalRectangle(vector<vector<char> > &matrix) 
    {
        if(matrix.size()==0||matrix[0].size()==0)
            return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        rectangle = new bool*[n];
        int max=0;
        
        for(int i=0;i<n;i++)
        {
            rectangle[i] = new bool[m];
        }
        
        
        for(int k=0;k<n;k++)
        {
            for(int l=0;l<m;l++)
            {
                rectangle[k][l]=(matrix[k][l]=='1');
                for(int i=k;i<n;i++)
                {
                    bool end = false;
                    for(int j=l;j<m;j++)
                    {
                        if(i==k&&j==l)
                        {
                            if(rectangle[i][j])
                            {
                                int area = 1;
                                if(area > max)
                                max = area;
                            }
                            else
                            {
                                end = true;
                                break;
                            }
                        }
                        else if(i==k)
                        {
                            rectangle[i][j] = rectangle[i][j-1] && (matrix[i][j]=='1');
                        }
                        else if(j==l)
                        {
                            rectangle[i][j] = rectangle[i-1][j] && (matrix[i][j]=='1');
                        }
                        else
                        {
                            rectangle[i][j] = rectangle[i][j-1] && rectangle[i-1][j] && (matrix[i][j]=='1');
                        }
                        if(rectangle[i][j])
                        {
                            int area = (i-k+1)*(j-l+1);
                            if(area > max)
                                max = area;
                        }
                        else
                        {
                            break;
                        }
                    }
                    if(end)
                    {
                        break;
                    }
                }
            }
        }
        return max;
    }
};