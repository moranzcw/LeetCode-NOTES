#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    vector<vector<int> > threeSum(vector<int> &num) 
    {
        vector<vector<int> > result;
        if(num.size() == 0)
            return result;

        vector<int> sortedArray(num);
        sort(sortedArray.begin(),sortedArray.end());

        for( int num1pos = 0;num1pos<sortedArray.size();num1pos++)
        {
            for(int num2pos = num1pos + 1, num3pos =sortedArray.size()-1; num2pos < num3pos;)
            {
                int sum = sortedArray[num2pos] + sortedArray[num3pos];
                if(sum == -sortedArray[num1pos] )
                {
                        vector<int> tempResult;
                        tempResult.push_back(sortedArray[num1pos]);
                        tempResult.push_back(sortedArray[num2pos]);
                        tempResult.push_back(sortedArray[num3pos]);
                        sort(tempResult.begin(),tempResult.end());
                        result.push_back(tempResult);

                        while( num2pos+1 < num3pos
                            && sortedArray[num2pos+1] == sortedArray[num2pos])
                            num2pos++;
                        num2pos++;
                        while( num3pos-1 > num2pos
                            && sortedArray[num3pos-1] == sortedArray[num3pos])
                            num3pos--;
                        num3pos--;
                }
                else if(sum <= -sortedArray[num1pos])
                {
                    num2pos++;
                }
                else
                {
                    num3pos--;
                }
            }
            while( num1pos+1 < sortedArray.size()
                && sortedArray[num1pos+1] == sortedArray[num1pos])
                num1pos++;
        }
        return result;
    }
};

int main()
{
    // test
    // int S[] = {4,-10,-11,-12,-8,-12,-14,-11,-6,2,-4,2,3,12,-3,-12,-14,-12,-8,-9,-6,-3,10,2,14,10,7,-7,-9,0,-9,10,-2,-5,14,5,-9,7,9,0,-14,12,10,4,9,-8,8,11,-5,-15,-13,-3,-11,4,14,11,-1,-2,-11,5,14,-4,-8,-3,6,-9,9,12,6,3,-10,7,0,-15,-3,-13,-8,12,13,-5,12,-15,7,8,-4,-2,4,2,3,9,-8,2,-10,-1,6,3,-2,0,-7,11,-12,-2,3,-4,-2,7,-2,-3,4,-12,-1,1,10,13,-5,-9,-12,6,8,7,0,7,-6,5,13,8,-14,-12};
    int S[] = {0,0,0};
    vector<int> num(S,S+sizeof(S)/sizeof(int));
    Solution sol;
    vector<vector<int> > result = sol.threeSum(num);
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++)
            cout<<result[i][j]<<" ";
        cout<<endl;
    }
}