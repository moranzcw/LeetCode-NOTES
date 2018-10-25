class Solution 
{
public:
    bool isPalindrome(string s) 
    {
        if(s.length() == 0)
            return true;

        for(int i=0,j=s.length()-1;i<j;i++,j--)
        {
            while( (s[i]<'0' 
                || (s[i]>'9' && s[i]<'A') 
                || (s[i]>'Z' && s[i]<'a')
                || (s[i]>'z') )
                && i<j )
                i++;
            while((s[j]<'0' 
                || (s[j]>'9' && s[j]<'A') 
                || (s[j]>'Z' && s[j]<'a')
                || (s[j]>'z') )
                && i<j )
                j--;
            if(s[i] != s[j]
                && s[i]-'A' != s[j]-'a' 
                && s[i]-'a' != s[j]-'A')
                return false;
        }
        return true;
    }
};