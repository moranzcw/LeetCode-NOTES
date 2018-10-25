class Solution 
{
public:
    string reverseString(string s) 
    {
        string result(s);
        for(int i=0;i<s.size();i++)
        {
            result[s.size()-1-i] = s[i];
        }
        return result;
    }
};