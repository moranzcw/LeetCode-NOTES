#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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

int main()
{
    int A[] = {1,2,3,4,5};
    int B[] = {6,7,8,9,10};
    int C[] = {11,12,13,14,15};
    int D[] = {16,17,18,19,20};
    int E[] = {21,22,23,24,25};
    vector<int> num1(A,A+5);
    vector<int> num2(B,B+5);
    vector<int> num3(C,C+5);
    vector<int> num4(D,D+5);
    vector<int> num5(E,E+5);
    vector<vector<int> > matrix;
    matrix.push_back(num1);
    matrix.push_back(num2);
    matrix.push_back(num3);
    matrix.push_back(num4);
    matrix.push_back(num5);

    Solution sol;
    sol.rotate(matrix);
    for (int i = 0; i < matrix.size(); ++i)
    {
        for(int j = 0;j < matrix[i].size();++j)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}