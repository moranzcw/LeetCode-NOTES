class Solution 
{
public:
    string longestPalindrome(string s) 
    {
        int position, maxLength=0, length=0;
        for(int i=0;i<s.size();i++)
        {
            length = 1;
            for(int j=1;i+j<s.size()&&i-j>=0;j++)
            {
                if(s[i-j] == s[i+j])
                    length += 2;
                else
                    break;
            }
            if(length > maxLength)
            {
                maxLength = length;
                position = i-length/2;
            }
        }
        
        for(int i=0;i+1<s.size();i++)
        {
            length = 0;
            for(int j=0;i+1+j<s.size()&&i-j>=0;j++)
            {
                if(s[i-j] == s[i+1+j])
                    length += 2;
                else
                    break;
            }
            if(length > maxLength)
            {
                maxLength = length;
                position = i-length/2+1;
            }
        }
        return s.substr(position,maxLength);
    }
};