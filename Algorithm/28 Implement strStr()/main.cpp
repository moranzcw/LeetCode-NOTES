#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution 
{
public:
    void getNext(char *patten, int next[]) 
    {
        int i = 0, j = -1;
        next[i] = j;
        while (patten[i] != '\0') 
        {
            while (j >= 0 && patten[i] != patten[j]) 
                j = next[j];
            ++i; ++j;
            next[i] = j;
        }
    }
    
    int strStr(char *haystack, char *needle) 
    {
        if (haystack == NULL || needle == NULL) 
            return -1;
        if (needle[0] == '\0') 
            return 0;
            
        int i = 0, j = 0;
        int pos = -1;
        int *next = new int[strlen(needle) + 1];
        getNext(needle, next);

        while (haystack[i] != '\0') 
        {
            while (j >= 0 && haystack[i] != needle[j])
                j = next[j];

            ++i; ++j;
            if (needle[j] == '\0') 
            {
                pos = i - j;
                return pos;
            }
        }
        return pos;
    }
};


int main()
{
    Solution sol;
    char haystack[] = "mississippi";
    char needle[] = "issip";
    cout << sol.strStr(haystack,needle) << endl;
    return 0;
}