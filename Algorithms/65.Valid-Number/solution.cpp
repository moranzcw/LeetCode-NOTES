class Solution 
{
public:
    bool isNumber(string s) 
    {
        int i=0;
        while (s[i] == ' ') 
            ++i;
        while (s[i] == '+' || s[i] == '-') 
            ++i;
        bool exp = false, space = false, point = false;
        bool number = false;
        while (s[i] != '\0') 
        {
            if (isdigit(s[i])) 
            {
                if (space) 
                    return false;
                else 
                    number = true;
            } 
            else if (s[i] == '.') 
            {
                if (!point && !space && !exp) 
                {
                    point = true;
                } 
                else 
                {
                    return false;
                }
            } 
            else if (s[i] == 'e') 
            {
                if (!exp && number && !space) 
                {
                    exp = true;
                    number = false;
                    while (s[i+1] == '+' || s[i+1] == '-') 
                        ++i;
                } 
                else 
                {
                    return false;
                }
            } 
            else if (s[i] == ' ') 
            {
                if (!space) 
                {
                    space = true;
                }
            } 
            else 
            {
                return false;
            }
            ++i;
        }
        return number;
    }
};