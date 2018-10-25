class Solution 
{
public:
    int longestPalindrome(string s) 
    {
        bool table[256];
        memset(table,0,sizeof(table));
        
        int result = 0;
        
        for(int i=0;i<s.size();i++)
        {
            if(table[s[i]])
            {
                table[s[i]] = false;
                result += 2;
            }
            else
                table[s[i]] = true;
        }
        if(s.size() > result)
            result++;
        return result;
    }
};