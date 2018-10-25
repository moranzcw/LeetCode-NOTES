class Solution 
{
public:
    string simplifyPath(string path) 
    {
        stack<string> s;
        string str;
        for(int i = 0; i < path.size(); i++)
        {
            if (path[i] == '/')
            {
                if (str == "..")
                {
                    if (!s.empty())
                        s.pop();
                }
                else if (str != "." && str != "")
                {
                    s.push(str);
                }

                str = "";
            }
            else
            {
                str += path[i];
            }
        }
        
        if (str == "..")
        {
            if (!s.empty())
                s.pop();
        }
        else if (str != "." && str != "")
            s.push(str);
        
        if (s.empty())
            return "/";
        
        string ret;
        while(!s.empty())
        {
            ret = "/" + s.top() + ret;
            s.pop();
        }
        
        return ret;
    }
};