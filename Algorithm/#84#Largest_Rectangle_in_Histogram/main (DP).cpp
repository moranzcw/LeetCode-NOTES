#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    int largestRectangleArea(vector<int>& height) 
    {
        vector<vector<int> > DP_height(height.size(),vector<int>(height.size(),0));
        vector<vector<int> > DP_width(height.size(),vector<int>(height.size(),0));
        for(int i=0;i<height.size();i++)
        {
            DP_width[i][i] = 1;
            DP_height[i][i] = height[i];
        }

        int max = 0;
        for(int i=1;i<height.size();i++)
        {
            for(int j=0;j+i<height.size();j++)
            {
                if(height[j+i] >= DP_height[j][j+i-1])
                {
                    if(DP_height[j][j+i-1]*(DP_width[j][j+i-1]+1) > height[j+i])
                    {
                        DP_width[j][j+i] = DP_width[j][j+i-1] + 1;
                        DP_height[j][j+i] = DP_height[j][j+i-1];
                    }
                    else
                    {
                        DP_width[j][j+i] = 1;
                        DP_height[j][j+i] = height[j+i];
                    }
                }
                else
                {
                    DP_width[j][j+i] = 1;
                    DP_height[j][j+i] = height[j+i];
                }
                if(DP_width[j][j+i]*DP_height[j][j+i] > max)
                    max = DP_width[j][j+i]*DP_height[j][j+i];
            }
        }
        return max;
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