class Solution {
public:
    string DFS(string s, int &k)
    {
        string ans;
        int cnt = 0;
        while(k < s.size())
        {
            if(isdigit(s[k])) cnt = cnt*10 + (s[k++]-'0');
            else if(s[k]=='[')
            {
                string tem = DFS(s, ++k);
                for(int i = 0; i < cnt; i++) ans += tem;
                cnt = 0;
            }
            else if(s[k]==']')
            {
                k++;
                return ans;
            }
            else ans += s[k++];
        }
        return ans;
    }
    
    string decodeString(string s) {
        int k = 0;
        return DFS(s, k);
    }
};