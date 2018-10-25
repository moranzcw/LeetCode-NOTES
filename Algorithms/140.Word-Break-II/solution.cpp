class Solution
{
public:
    vector<string> result;

    void printStack(stack<string> stk)
    {
        string output = "";
        while(!stk.empty())
        {
            if(output == "")
                output += stk.top();
            else
                output = output + " " + stk.top();
            stk.pop();
        }
        result.push_back(output);
    }

    void check(vector<vector<int> > &v, int t, stack<string> stk, string s)
    {
        if(t == -1)
        {
            printStack(stk);
            return ;
        }
        else
        {
            for(vector<string>::size_type st = 0; st < v[t].size(); st ++)
            {
                stk.push(s.substr(v[t][st]+1, t-v[t][st]));
                check(v, v[t][st], stk, s);
                stk.pop();
            }
        }

    }

    vector<vector<int> > buildv(string s, unordered_set<string> &dict)
    {
        vector<vector<int> > v(s.length());
        for(string::size_type st1 = 0; st1 < s.length(); st1 ++)
        {
            for(string::size_type st2 = 0; st2 <= st1; st2 ++)
            {
                if(dict.find(s.substr(st2, st1-st2+1)) != dict.end())
                {
                    if(st2 == 0)
                        v[st1].push_back(-1);
                    else if(!v[st2-1].empty())
                        v[st1].push_back(st2-1);
                }
            }
        }
        return v;
    }

    vector<string> wordBreak(string s, unordered_set<string> &dict) 
    {
        vector<vector<int> > v = buildv(s, dict);
        stack<string> stk;
        check(v, v.size()-1, stk, s);

        return result;
    }
};