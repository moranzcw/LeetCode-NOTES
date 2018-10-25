// class Solution 
// {
// public:
//     int strStr(string haystack, string needle) 
//     {
//         if(needle.size() == 0) return 0;
//         for(int i=0;i<haystack.size();i++)
//         {
//             int j = 0;
//             for(j;j<needle.size();j++)
//             {
//                 if(haystack[i+j] != needle[j])
//                     break;
//             }
//             if(j == needle.size())
//                 return i;
//         }
//         return -1;
//     }
// };

class Solution {
public: 
    int strStr(string haystack, string needle) 
    {
        int m = haystack.length(), n = needle.length();
        if (!n) return 0;
        for (int i = 0; i < m - n + 1; i++) 
        {
            int j = 0;
            for (; j < n; j++)
                if (haystack[i + j] != needle[j])
                    break;
            if (j == n) return i;
        }
        return -1;
    }
};