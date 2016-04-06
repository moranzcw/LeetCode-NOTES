#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;
 
#define INT_MAX ((int)(~0U>>1))
#define INT_MIN (-INT_MAX - 1)

class Solution 
{
public:
    bool canTranslate(const string &str1, const string &str2)
    {
        if(str1.size() != str2.size())
            return false;
        if(str1.size() == 0)
            return false;

        int count = 0;
        for(int i=0;i<str1.size();i++)
        {
            if(str1[i] != str2[i])
                count++;
        }
        if(count == 1)
            return true;
        return false;
    }

    int ladderLength(string start, string end, unordered_set<string> &dict) 
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
    cout <<sol.ladderLength(start,end,dict) << endl;
    return 0;
}