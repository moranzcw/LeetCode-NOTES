#include <iostream>
using namespace std;

class Solution 
{
public:
    bool isAnagram(string s, string t) 
    {
        int flag[128] = {false};
        for(int i=0;i<s.size();i++)
            flag[s[i]] = true;
        for(int i=0;i<t.size();i++)
            if(flag[t[i]] == false)
                return false;
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    string a = "anagram";
    string b = "nagaram";
    cout<<sol.isAnagram(a,b)<<endl;
    return 0;
}