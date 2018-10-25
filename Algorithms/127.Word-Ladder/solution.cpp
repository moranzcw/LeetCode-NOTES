class Solution 
{
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) 
    {
        if(start.size() != end.size()) return 0;
        if(start.empty() || end.empty())return 0;
        
        queue<string> path;
        path.push(start);
        int level = 1;
        int count = 1;
        dict.erase(start);
        while(dict.size() > 0 && !path.empty())
        {
            string curword = path.front();
            path.pop();count--;
            for(int i = 0; i < curword.size(); i++)
            {
                string tmp = curword;
                for(char j='a'; j<='z'; j++)
                {
                    if(tmp[i]==j)continue;
                    tmp[i] = j;
                    if(tmp==end)return level+1;
                    if(dict.find(tmp) != dict.end()) path.push(tmp);
                    dict.erase(tmp);
                }
            }
            if(count==0)
            {
                count = path.size();
                level++;
            }
        }
        return 0;
    }
};