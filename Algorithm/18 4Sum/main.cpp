#include <iostream>
// #include <limits>  
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
        vector<vector<int> > fourSum(vector<int> &num, int target) 
        {
            vector<vector<int> > res;
            int numlen = num.size();
            if(num.size()<4)
                return res;
            
            sort(num.begin(),num.end());
            set<vector<int> > tmpres;
            for(int i = 0; i < numlen; i++)
            {
                for(int j = i+1; j < numlen; j++)
                {
                    int begin = j+1;
                    int end = numlen-1;
                    while(begin < end)
                    {
                        int sum = num[i]+ num[j] + num[begin] + num[end];
                        if(sum == target)
                        {
                            vector<int> tmp;
                            tmp.push_back(num[i]);
                            tmp.push_back(num[j]);
                            tmp.push_back(num[begin]);
                            tmp.push_back(num[end]);
                            tmpres.insert(tmp);
                            begin++;
                            end--;
                        }
                        else if(sum<target)
                            begin++;
                        else
                            end--;
                    }
                }
            }
            set<vector<int> >::iterator it = tmpres.begin();
            for(; it != tmpres.end(); it++)
                res.push_back(*it);
            return res;
        }
};

int main()
{
    // test
    int S[] = {1,0,-1,0,-2,2};
    vector<int> num(S,S+sizeof(S)/sizeof(int));
    Solution sol;
    vector<vector<int> > result = sol.fourSum(num,0);
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}