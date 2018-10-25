class Solution
{
public:
    bool isValid(string s) 
    {
        stack<char> stk;
        for(int i=0;i<s.size();i++)
        {
            switch(s[i])
            {
                case '(': stk.push(')');break;
                case '[': stk.push(']');break;
                case '{': stk.push('}');break;
                case ')': 
                case ']':
                case '}':
                    if(stk.empty() || stk.top() != s[i]) 
                        return false;
                    else
                        stk.pop();
                    break;
            }
        }
        if(!stk.empty())
            return false;
        return true;
    }
};