class Solution 
{
public:
    int characterReplacement(string s, int k) 
    {
        int len = s.length();
        int maxlen = 0,tl=0;//tl是tmp_len，当前字符的最长重复值
        for (int i = 0; i < len; ++i) 
        {
            if (i > 0 && s[i] == s[i-1]) 
                continue;
            char cur_letter = s[i];
            int count = k;
            int j;
            for (j = i+1; j < len; ++j) 
            {
                if (s[j] != cur_letter) 
                    count--;
                if (count < 0) 
                    break;
            }
            if(j==len&&count>0)
                tl=j-i+min(count,i);
            else 
                tl=j-i;
            maxlen = max(maxlen, tl);
        }
        return maxlen;
    }
};