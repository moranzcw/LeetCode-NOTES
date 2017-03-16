#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution 
{
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) 
    {
        
    }
};

int main()
{
    string start = "hit";
    string end = "cog";
    string d[] = {"hot","dot","dog","lot","log"};
    unordered_set<string> dict(d,d+5);
    Solution sol;
    sol.findLadders(start,end,dict);
    return 0;
}