#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution 
{
public:
    int maxArea(vector<int> &height)
    {
        int head = 0;
        int tail = height.size() -1;

        int maxArea = 0;
        while(head < tail)
        {
            int area = (tail - head)*min(height[head],height[tail]);
            maxArea = max(maxArea,area);

            if(height[head] < height[tail])
                head++;
            else
                tail--;
        }
        return maxArea;
    }
};

int main()
{
    Solution sol;
    int t[] = {0,14,6,2,10,9,4,1,10,3};
    vector<int> test(t,t+10);
    cout << sol.maxArea(test)<<endl;
    return 0;
}