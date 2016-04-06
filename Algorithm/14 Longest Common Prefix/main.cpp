#include <vector>
#include <iostream>
using namespace std;

class Solution 
{
public:
    string longestCommonPrefix(vector<string> &strs) 
    {
        if( strs.size() == 0)
            return "";
        string prefix = strs[0];
        for(int i = 0;i<strs.size();i++)
        {
            if(prefix.size() == 0 || strs[i].size() == 0)
                return "";
            int j = 0;
            while(prefix[j] == strs[i][j])
            {
                j++;
            }
            prefix = prefix.substr(0,j);
        }
        return prefix;
    }
};

int main()
{
    Solution sol;
    vector<string> test;
    test.push_back("abcd");
    test.push_back("abcdef");
    test.push_back("abcde");
    test.push_back("");
    cout << sol.longestCommonPrefix(test) << endl;
    return 0;
}