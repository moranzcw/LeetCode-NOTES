#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    int searchInsert(int A[], int n, int target) 
    {
        int i = 0; 
        int j = n - 1;
        
        while (i <= j) 
        {
            int mid = (int)((i + j)/2);
            if (A[mid] == target) 
                return mid;
            else if (A[mid] > target) 
                j = mid - 1;
            else 
                i = mid + 1;
        }
        return i;
    }
};

int main()
{
    int a[] = {5, 6, 7, 8, 9, 10};
    Solution sol;
    cout<<sol.searchInsert(a,6,11)<<endl;
    return 0;
}