class Solution 
{
public:
    vector<int> getRow(int rowIndex) 
    {
        vector<vector<int> > result;
        vector<int> temp;

        temp.push_back(1);
        result.push_back(temp);
        if(rowIndex == 0)
            return result[0];

        temp.push_back(1);
        result.push_back(temp);
        if(rowIndex == 1)
            return result[1];

        for(int i=2;i<rowIndex+1;i++)
        {
            vector<int> temp;
            temp.push_back(1);
            for(int j=0;j<i-1;j++)
            {
                temp.push_back(result[i-1][j] + result[i-1][j+1]);
            }
            temp.push_back(1);
            result.push_back(temp);
        }
        return result[rowIndex];
    }
};