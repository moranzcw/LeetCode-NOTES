#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution 
{
public:
    int singleNumber(vector<int>& nums) 
    {
        multiset<int> S;
        for(int i=0;i<nums.size();i++)
        {
            if(S.count(nums[i])>1)
                S.erase(nums[i]);
            else
                S.insert(nums[i]);
        }
        return *S.begin();
    }
};

int main()
{
    int A[] = {1,1,1,2,2,2,3,3};
    vector<int> nums(A,A+8);
    Solution sol;
    cout<<sol.singleNumber(nums)<<endl;
    return 0;
}