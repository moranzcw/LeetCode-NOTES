#include <iostream>
#include <cstring>
using namespace std;

class Solution 
{
public:
    void rotate(int nums[], int n, int k) 
    {  
        k = k % n;  
        if (k == 0) return;  
        int *temp = new int[n];  
        memcpy(temp, nums+(n-k), sizeof(int)*k);  
        memcpy(temp+k, nums, sizeof(int)*(n-k));  
        memcpy(nums, temp, sizeof(int)*n);  
        delete[] temp;  
    }  
};


int main()
{
    int nums[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27};
    Solution sol;
    sol.rotate(nums,27,11);
    for(int i=0;i<27;i++)
    {
        cout<<nums[i]<<" ";
    }
    cout << endl;
    return 0;
}