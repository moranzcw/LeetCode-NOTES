#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    vector<int> nextPermutation(vector<int> &num) 
    {
        if(num.size() < 2) 
            return num;
        int curMax = num[num.size() - 1];
        for(int i = num.size() - 1; i >= 0;i--)
        {
            if(num[i] < curMax)
            {
                int tmp = num[i];
                int j = 0;
                for(j = i + 1; j < num.size();j++)
                {
                    if(tmp < num[j])
                    {
                        num[i] = num[j];
                        num[j] = tmp;
                        return num;
                    }
                }
                if(j == num.size())
                {
                    num[j - 1] = tmp;
                    return num;
                }
            }
            else
            {
                curMax = num[i];
                for(int j = i + 1; j < num.size();j++)
                    num[j - 1] = num[j];
                num[num.size() - 1] = curMax;
            }
        }
        return num;
    }

    vector<vector<int> > permute(vector<int> &num) 
    {
        long long n = num.size();
        for(int i=n-1;i>0;i--)
            n *= i;
        vector<vector<int> > result;
        while(n--)
            result.push_back(nextPermutation(num));
        return result;
    }
};

int main()
{
    int S[] = {1,2,3};
    vector<int> num(S,S+3);
    Solution sol;
    vector<vector<int> > result = sol.permute(num);
    for (int i = 0; i < result.size(); ++i)
    {
        for(int j = 0;j < result[i].size();++j)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}