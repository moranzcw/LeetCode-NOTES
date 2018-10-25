class Solution 
{
public:
    string convertToTitle(int n) 
    {
        if(n < 1)
            return "";
        else
        {
            string result = "";
            while(n)
            {
                n --;
                char c = n%26 + 'A';
                result += c;
                n /= 26;
            }
            reverse(result.begin(), result.end());
            return result;
        }
    }
};