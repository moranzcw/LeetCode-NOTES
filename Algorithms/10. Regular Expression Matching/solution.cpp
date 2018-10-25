class Solution 
{
public:
    bool match(string &s,string &p,int i,int j)
    {
        // pattern已匹配完，检查字符串是否匹配完 
        if(j == p.size()) 
            return i == s.size();
        
        // pattern中，当前待匹配字符的后一个字符为'*'的情况
        if(p[j+1] == '*')
        {
            // 如果能匹配，则可以让'*'号重复0次或多重复1次；不能匹配，则让'*'号重复0次
            if((s[i] == p[j] || p[j] == '.') && i<s.size())
                return match(s,p,i,j+2) || match(s,p,i+1,j);
            return match(s,p,i,j+2);
        }
        
        // pattern中，当前待匹配字符的后一个字符不为'*'的情况    
        if(s[i] == p[j] || p[j] == '.')
            return match(s,p,i+1,j+1);
        return false;
    }
    
    bool isMatch(string s, string p) 
    {
        return match(s,p,0,0);
    }
};