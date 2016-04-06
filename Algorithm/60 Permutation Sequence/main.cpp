#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution 
{
public:
    string getPermutation(int n, int k) 
    {
        vector<int> nums(n);
        int pCount = 1;
        for(int i = 0 ; i < n; ++i) 
        {
            nums[i] = i + 1;
            pCount *= (i + 1);
        }

        k--;
        string res = "";
        for(int i = 0 ; i < n; i++) 
        {
            pCount = pCount/(n-i);
            int selected = k / pCount;
            res += ('0' + nums[selected]);
            
            for(int j = selected; j < n-i-1; j++)
                nums[j] = nums[j+1];
            k = k % pCount;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    cout << sol.getPermutation(3,1) <<endl;
    cout << sol.getPermutation(3,2) <<endl;
    cout << sol.getPermutation(3,3) <<endl;
    cout << sol.getPermutation(3,4) <<endl;
    cout << sol.getPermutation(3,5) <<endl;
    cout << sol.getPermutation(3,6) <<endl;
    return 0;
}