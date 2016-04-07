#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution 
{
public:
    int singleNumber(vector<int>& nums) 
    {
        set<int> S;
        for(int i=0;i<nums.size();i++)
        {
            if(S.count(nums[i])>0)
                S.erase(nums[i]);
            else
                S.insert(nums[i]);
        }
        return *S.begin();
    }
};

int main()
{
    int A[] = {1,2,3,3,2};
    vector<int> nums(A,A+5);
    Solution sol;
    cout<<sol.singleNumber(nums)<<endl;
    return 0;
}