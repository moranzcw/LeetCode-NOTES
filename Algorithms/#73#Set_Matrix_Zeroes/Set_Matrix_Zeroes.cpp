#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    void setZeroes(vector<vector<int> > &matrix) 
    {
        bool firstLine = false, firstRow = false;
        for(int i=0;i<matrix[0].size();i++)
            if(matrix[0][i] == 0)
                firstRow = true;
        for(int i=0;i<matrix.size();i++)
            if(matrix[i][0] == 0)
                firstLine = true;

        for(int i=1;i<matrix.size();i++)
        {
            for(int j=1;j<matrix[i].size();j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for(int i=1;i<matrix[0].size();i++)
        {
            if(matrix[0][i] == 0)
            {
                for(int j=0;j<matrix.size();j++)
                    matrix[j][i] = 0;
            }
        }

        for(int i=1;i<matrix.size();i++)
        {
            if(matrix[i][0] == 0)
            {
                for(int j=0;j<matrix[i].size();j++)
                    matrix[i][j] = 0;
            }
        }

        if(firstRow)
            for(int i=0;i<matrix[0].size();i++)
                matrix[0][i] = 0;
        if(firstLine)
            for(int i=0;i<matrix.size();i++)
                matrix[i][0] = 0;
    }
};

int main(int argc, char const *argv[])
{
    int A[] = {1,1,1};
    int B[] = {0,1,2};
    int C[] = {0,1,1,4};
    int D[] = {1,2,1,3};
    int E[] = {0,0,1,1};
    vector<vector<int> > matrix;
    matrix.push_back(vector<int>(A,A+3));
    matrix.push_back(vector<int>(B,B+3));
    // matrix.push_back(vector<int>(C,C+4));
    // matrix.push_back(vector<int>(D,D+4));
    // matrix.push_back(vector<int>(E,E+4));
    Solution sol;
    sol.setZeroes(matrix);
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[i].size();j++)
            cout<< matrix[i][j] <<" ";
        cout<<endl;
    }
    cout<<endl;
    return 0;
}