#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    vector<vector<int> > matrix;

    void solve(int startPos, int startNum, int n)
    {
        if(n <= 0)
            return ;
        else  
        {
            for(int i=startPos;i<startPos+n;i++)
            {
                matrix[startPos][i] = startNum;
                startNum++;
            }
            for(int i=startPos+1;i<startPos+n;i++)
            {
                matrix[i][startPos+n-1] = startNum;
                startNum++;
            }
            for(int i=startPos+n -2;i> startPos-1;i--)
            {
                matrix[startPos+n-1][i] = startNum;
                startNum++;
            }
            for(int i=startPos+n -2;i>startPos;i--)
            {
                matrix[i][startPos] = startNum;
                startNum++;
            }
            solve(startPos+1,startNum,n-2);
        }
    }

    vector<vector<int> > generateMatrix(int n) 
    {
        matrix.resize(n,vector<int>(n));
        solve(0,1,n);
        return matrix;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<vector<int> > result = sol.generateMatrix(6);
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++)
            cout<<result[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}