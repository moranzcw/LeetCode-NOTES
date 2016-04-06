#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    vector<string> anagrams(vector<string> &strs) 
    {
        string s;
        map<string, int> anagram;
        vector<string> result;
        for (int i = 0; i < strs.size(); ++i) 
        {
            s = strs[i];
            sort(s.begin(), s.end());
            if (anagram.find(s) == anagram.end()) 
            {
                anagram[s] = i;
            } 
            else 
            {
                if (anagram[s] >= 0) 
                {
                    result.push_back(strs[anagram[s]]);
                    anagram[s] = -1;
                }
                result.push_back(strs[i]);
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    string str[] = {"tea","and","ate","eat","den"};
    vector<string> strs(str,str+5);
    Solution sol;
    vector<string> result(sol.anagrams(strs));
    for(vector<string>::iterator it = result.begin(); it != result.end();it++)
    {
        cout<<(*it)<<endl;
    }
    return 0;
}