class Solution 
{
public:
    int firstUniqChar(string s) 
    {
        int table[26];
        memset(table,0,sizeof(table));
        
        for(int i=0;i<s.size();i++)
        {
            table[s[i]-'a'] += 1;
        }
        for(int i=0;i<s.size();i++)
        {
            if(table[s[i]-'a'] == 1)
                return i;
            // cout<<i<<" "<<s[i]<<" "<<table[s[i]]<<endl;
        }
        return -1;
    }
};