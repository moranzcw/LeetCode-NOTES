#include <iostream>
using namespace std;

bool isExist[256];
int position[256];

class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        int start = 0;
        int max = 0;

        for(int i=0;i<256;i++)
        {
            isExist[i] = false;
            position[i] = 0;
        }

        for(int i=0;i < s.size();i++)
        {
            if(isExist[s[i]])
            {
                for(int j=start;j <= position[s[i]];j++)
                {
                    isExist[s[j]] = false;
                }
                start = position[s[i]] + 1;
                isExist[s[i]] = true;
                position[s[i]] = i;            
            }
            else
            {
                isExist[s[i]] = true;
                position[s[i]] = i;
                max = max > (i - start + 1) ? max : (i - start + 1);
            }
        }
        return max;
    }
};

int main()
{
    /* test */
    Solution sol;
    cout << sol.lengthOfLongestSubstring("asdfghjkiuytr245879`") << endl;;
}