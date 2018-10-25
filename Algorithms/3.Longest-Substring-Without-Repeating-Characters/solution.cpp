class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        int left=0, right=0;
        int maxLength=0, length=0;
        vector<bool> flag(255,false);
        for(;right<s.size();right++)
        {
            if(flag[s[right]] == true)
            {
                for(;s[left] != s[right];left++)
                {
                    flag[s[left]] = false;
                    length --;
                }
                left++;
            }
            else
            {
                flag[s[right]] = true;
                length++;
                if(length > maxLength) 
                    maxLength = length;
            }
        }
        return maxLength;
    }
};