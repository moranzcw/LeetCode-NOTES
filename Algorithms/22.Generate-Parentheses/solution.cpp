class Solution 
{
public:
    void generate(vector<string> &strList, string str, int k, int length)
    {
        if(str.size() == length)
        {
            if(k==0) strList.push_back(str);
            return;
        }
        if(k>0)
        {
            generate(strList, str+')', k-1, length);
        }
        generate(strList, str+'(', k+1, length);
    }
    
    vector<string> generateParenthesis(int n) 
    {
        vector<string> strList;
        string str;
        generate(strList, str, 0, n*2);
        return strList;
    }
};