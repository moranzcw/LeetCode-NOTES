#include <iostream>
using namespace std;

class Solution 
{
public:
    bool search(int A[], int n, int target) 
    {
        if(NULL == A || 0 == n)
            return false;
        int left = 0, right = n-1, mid = 0;
        while(left <= right)
        {
            mid = left+(right-left)/2;
            if(A[mid] == target)
                return true;
            bool isLeft = true;
            for(int i = left; i <= mid; ++i)
                if(A[i] > A[mid])
                {
                    isLeft = false;
                    break;
                }
            if(isLeft)//left
            {
                if(A[left] <= target && target < A[mid])
                    right = mid - 1;
                else
                    left = mid + 1;

            }
            else//right
            {
                if(A[mid] < target && target <= A[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }

        return false;
    }
};

int main(int argc, char const *argv[])
{
    int A[] = {4,4,5,1,1,1,2,2,3};
    Solution sol;
    int l =sol.search(A,9,7);
    cout<<l<<endl;
    return 0;
}