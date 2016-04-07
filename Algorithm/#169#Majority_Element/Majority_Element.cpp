#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    int majorityElement(vector<int> &num) 
    {
        int n = num.size();  
        sort(num.begin(),num.end());  
        return num[n/2]; 
    }
};

int main()
{
    vector<int> test;
    test.push_back(1);
    test.push_back(0);
    test.push_back(3);
    test.push_back(2);
    test.push_back(2);
    test.push_back(2);
    test.push_back(2);
    Solution sol;
    cout<<sol.majorityElement(test)<<endl;
    return 0;
}