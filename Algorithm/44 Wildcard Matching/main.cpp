#include <iostream>
using namespace std;

class Solution 
{
public:
    bool isMatch(const char *s, const char *p) 
    {
        //greedy
        bool pre,next;
        const char *start,*end,*mid;
        const char *ss,*se,*sm;
        start = p;
        end = p;
        ss = s;
        while(true)
        {
            if(*start == '*')
                pre = true;//查看前面有没有*
            else 
                pre = false;
            //查看新的没有*的word
            while(*start != '\0' && *start == '*') 
                start++;
            end = start;
            
            while(*end != '\0' && *end != '*') 
                end++;
            if(*end == '*') 
                next = true;
            else 
                next = false;
            end--;
            
            if(*ss == '\0' && pre && *start == '\0')
                return true;//p和s均完全匹配
            if(*ss != '\0' && pre && *start == '\0') 
                return true;
            if(*ss != '\0' && (*start == '\0' && !pre)) 
                return false;//s没能完全匹配
            if(*ss == '\0' && *start != '\0') 
                return false;//p的字母没能匹配完全
            
            //处理greedy匹配问题
            if(next == true)
            {//后面有*可供匹配
                if(pre == true)
                {//前面有供做匹配的
                    sm = ss,mid = start;//判断s中剩余的还够匹配不够
                    while(mid != end && *sm != '\0')
                    {
                        mid++,sm++;
                    }
                    if(*sm == '\0')
                        return false;

                    mid = start;
                    while(*mid != '*' && *ss != '\0')
                    {
                        for(sm = ss,mid = start;*sm != '\0' && *mid != '*';sm++,mid++)
                        {
                            if(*mid == '?')continue;
                            if(*mid != *sm)break;
                        }
                        if(*mid == '*')
                            ss = sm;
                        else 
                            ss++;
                    }//while
                    if(*mid != '*')
                        return false;
                    ss = sm;
                    start = mid;
                }
                else
                {//前面没有供匹配的
                    for(sm = ss,mid = start;*sm != '\0' && mid != end+1;sm++,mid++)
                    {
                        if(*mid == '?')
                            continue;
                        if(*mid != *sm)
                            return false;
                    }
                    if(mid != end+1)
                        return false;
                    ss = sm;//匹配成功
                    start = end+1;
                }
            }
            else
            {//最后必须匹配的一串，因为后面没有*可供匹配最后的字母
                if(pre)
                {
                    se = ss;
                    while(*se != '\0')
                        se++;
                    se--;
                    for(sm = se,mid = end;mid != start && sm != ss;mid--,sm--)
                    {
                        if(*mid == '?')
                            continue;
                        if(*mid != *sm)
                            return false;
                    }
                    if((sm == ss && mid != start) || (*mid != *sm && *mid != '?'))
                        return false;//如果s不够匹配或者p开头不能匹配
                    return true;
                }
                else
                {
                    for(sm = ss,mid = start;*sm != '\0' && *mid !='\0';sm++,mid++)
                    {
                        if(*mid == '?')
                            continue;
                        if(*mid != *sm)
                            return false;
                    }
                    if(*sm != '\0' || *mid != '\0')
                        return false;
                    return true;
                }
            }
        }
    }
};

int main()
{
    Solution sol;
    cout<<sol.isMatch("abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb", "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb")<<endl;
    return 0;
}