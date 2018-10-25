class Solution 
{
public:
    bool wordPattern(string pattern, string str) 
    {
        vector<string> strList;
        string temp;
        for(int i=0;i<str.size();i++)
        {
            if(str[i] != ' ')
                temp += str[i];
            else
            {
                strList.push_back(temp);
                temp = "";
            }
        }
        strList.push_back(temp);
        
        if(pattern.size() != strList.size())
            return false;
            
        unordered_map<char,string> table1;
        for(int i=0;i<pattern.size();i++)
        {
            if(table1.find(pattern[i]) == table1.end())
                table1[pattern[i]] = strList[i];
            else
            {
                if(table1[pattern[i]] != strList[i])
                    return false;
            }
        }
        
        unordered_map<string,char> table2;
        for(int i=0;i<strList.size();i++)
        {
            if(table2.find(strList[i]) == table2.end())
                table2[strList[i]] = pattern[i];
            else
            {
                if(table2[strList[i]] != pattern[i])
                    return false;
            }
        }
        return true;
    }
};