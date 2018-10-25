class Solution 
{
private:
    vector<string> ret;
    int pos[4];
public:
    bool check(string &s, int beg, int end)
    {
        string ip(s, beg, end - beg + 1);
        if (ip.size() == 1)
            return "0" <= ip && ip <= "9";
        else if (ip.size() == 2)
            return "10" <= ip && ip <= "99";
        else if (ip.size() == 3)
            return "100" <= ip && ip <= "255";
        else
            return false;
    }
    
    void dfs(int dep, int maxDep, string &s, int start)
    {
        if (dep == maxDep)
        {
            if (start == s.size())
            {
                int beg = 0;
                string addr;
                for(int i = 0; i < maxDep; i++)
                {
                    string ip(s, beg, pos[i] - beg + 1);
                    beg = pos[i] + 1;
                    addr += i == 0 ? ip : "." + ip;
                }
                ret.push_back(addr);    
            }
            return;
        }
        
        for(int i = start; i < s.size(); i++)
            if (check(s, start, i))
            {
                pos[dep] = i;
                dfs(dep + 1, maxDep, s, i + 1);               
            }
    }
    
    vector<string> restoreIpAddresses(string s) 
    {
        ret.clear();
        dfs(0, 4, s, 0);
        return ret;
    }
};