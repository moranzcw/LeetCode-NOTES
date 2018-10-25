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