#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    vector<vector<int> > generate(int numRows) 
    {
        vector<vector<int> > result;

        if(numRows == 0)
            return result;

        vector<int> temp;
        temp.push_back(1);
        result.push_back(temp);
        if(numRows == 1)
            return result;

        temp.push_back(1);
        result.push_back(temp);
        if(numRows == 2)
            return result;

        for(int i=2;i<numRows;i++)
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
        return result;
    }
};

int main()
{
    Solution sol;
    vector<vector<int> > result = sol.generate(5);
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++)
        {
            cout << result[i][j] << " ";
        }
        cout<<endl;
    }
    return 0;
}