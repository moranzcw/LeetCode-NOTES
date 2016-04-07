#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    void nextPermutation(vector<int> &num) 
    {
        if(num.size() < 2) return;
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
                        return;
                    }
                }
                if(j == num.size())
                {
                    num[j - 1] = tmp;
                    return;
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
    }
};

int main()
{
    vector<int> num;
    num.push_back(1);
    num.push_back(3);
    num.push_back(2);
    Solution sol;
    sol.nextPermutation(num);
    for(int i=0;i<num.size();i++)
        cout<<num[i]<<" ";
    cout<<endl;
    return 0;
}