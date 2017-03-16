#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    int transform(vector<vector<int> > &matrix, int index)
    {
        return matrix[index/matrix[0].size()][index%matrix[0].size()];
    }

    int bSearch(vector<vector<int> > &matrix, int begin, int end, int target)
    {
        if(begin <= end)
        {
            int mid = (begin+end)/2;
            int temp = transform(matrix,mid);
            if(target == temp)
                return mid;
            else if(target < temp)
                return  bSearch(matrix,begin,mid-1,target);
            else
                return  bSearch(matrix,mid+1,end,target);
        }
        else
            return -1;
    }

    bool searchMatrix(vector<vector<int> > &matrix, int target) 
    {
        if (bSearch(matrix,0,matrix.size()*matrix[0].size()-1,target) >= 0)
            return true;
        else
            return false;
    }
};

int main()
{
    int A1[] = {1,   3,  5,  7};
    int A2[] = {10, 11, 16, 20};
    int A3[] = {23, 30, 34, 50};
    vector<vector<int> > matrix;
    matrix.push_back(vector<int>(A1,A1+4));
    matrix.push_back(vector<int>(A2,A2+4));
    matrix.push_back(vector<int>(A3,A3+4));

    Solution sol;
    cout<<sol.searchMatrix(matrix,1)<<endl;
    cout<<sol.searchMatrix(matrix,2)<<endl;
    cout<<sol.searchMatrix(matrix,3)<<endl;
    cout<<sol.searchMatrix(matrix,4)<<endl;
    cout<<sol.searchMatrix(matrix,5)<<endl;
    cout<<sol.searchMatrix(matrix,6)<<endl;
    cout<<sol.searchMatrix(matrix,50)<<endl;
    return 0;
}