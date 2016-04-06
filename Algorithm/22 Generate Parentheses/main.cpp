#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
private:
    vector<string> result;
    int bracketSum;
public:
    void generate(string tempResult,int matchedSum, int leftBracketSum)
    {
        if( matchedSum == bracketSum)
        {
            result.push_back(tempResult);
            return;
        }
        if( leftBracketSum+matchedSum == bracketSum)
        {
            tempResult += ")";
            matchedSum ++;
            leftBracketSum --;
            generate(tempResult,matchedSum,leftBracketSum);
        }
        if( leftBracketSum+matchedSum < bracketSum && leftBracketSum > 0)
        {
            for(int i=0;i<2;i++)
            {
                if(i==0)
                {
                    // tempResult += "(";
                    // leftBracketSum ++;
                    generate(tempResult+"(",matchedSum,leftBracketSum+1);
                }
                if(i == 1)
                {
                    // tempResult += ")";
                    // matchedSum ++;
                    // leftBracketSum --;
                    generate(tempResult+")",matchedSum+1,leftBracketSum-1);                    
                }
            }
        }
        if( leftBracketSum+matchedSum < bracketSum && leftBracketSum == 0)
        {
            tempResult += "(";
            leftBracketSum ++;
            generate(tempResult,matchedSum,leftBracketSum);     
        }

    }
    vector<string> generateParenthesis(int n) 
    {
        int leftBracketSum = 0;
        bracketSum = n;
        generate("",0,0);
        return result;
    }
};

int main()
{
    Solution sol;
    vector<string> result = sol.generateParenthesis(3);
    for(int i=0;i<result.size();i++)
    {
        cout << result[i] <<endl;
    }
    return 0;
}