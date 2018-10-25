class Solution 
{
public:
    vector<string> letterCombinations(string digits) 
    {
        vector<string> result;
        if(digits == "")
            return result;
            
        result.push_back("");
        
        vector<string> dict(10);
        dict[2] = "abc";
        dict[3] = "def";
        dict[4] = "ghi";
        dict[5] = "jkl";
        dict[6] = "mno";
        dict[7] = "pqrs";
        dict[8] = "tuv";
        dict[9] = "wxyz";
        
        for(int i = 0; i < digits.size(); i ++)
        {
            int size = result.size();
            for(int j = 0; j < size; j ++)
            {
                string current = result[0];
                result.erase(result.begin());
                for(int k = 0; k < dict[digits[i]-'0'].size(); k ++)
                    result.push_back(current + dict[digits[i]-'0'][k]);
            }
        }
        return result;
    }
};