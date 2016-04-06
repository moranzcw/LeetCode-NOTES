#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution 
{
public:
    int Max(int a, int b){return a > b ? a : b;}
    int largestRectangleArea(vector<int> &height) 
    {
        height.push_back(0);
        stack<int> stk;
        int i = 0;
        int maxArea = 0;
        while(i < height.size())
        {
            if(stk.empty() || height[stk.top()] <= height[i])
            {
                stk.push(i++);
            }
            else 
            {
                int t = stk.top();
                stk.pop();
                maxArea = Max(maxArea, height[t] * (stk.empty() ? i : i - stk.top() - 1));
            }
        }
        return maxArea;
    }
};

int main(int argc, char const *argv[])
{
    int a[] = {2,1,5,6,2,3};
    vector<int> height(a,a+6);
    Solution sol;
    cout<<sol.largestRectangleArea(height)<<endl;
    return 0;
}