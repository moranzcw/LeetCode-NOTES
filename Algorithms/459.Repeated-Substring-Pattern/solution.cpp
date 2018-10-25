class Solution 
{
public:
    bool ok(string str, int i)
    {
        string t(str,0,i);
        for(int j=i;j<str.size();j+=i)
        {
            if(t!=str.substr(j,i))
            return false;
        }
        return true;
    }
    bool repeatedSubstringPattern(string str) 
    {
        int n=str.size();
        for(int i=1;i<=n/2;i++)
        {
            if(n%i!=0) continue;
            if(ok(str,i))
            return true;
        }
        return false;
    }
};