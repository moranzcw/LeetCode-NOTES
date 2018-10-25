class Solution 
{
public:
    void swap(string &str,int pos1,int pos2)  
    {  
        char temp = str[pos2];  
        str[pos2] = str[pos1];  
        str[pos1] = temp;  
    }  
    
    string reverseVowels(string s) 
    {
        char base[10]={'a','e','i','o','u','A','E','I','O','U'};
        set<char> seting(base,base+10);
        int startpos=0,endpos=s.size()-1;
        while(startpos < endpos )
        {
            while( startpos < endpos && seting.find(s[startpos]) == seting.end())
                startpos++;
            while( startpos < endpos && seting.find(s[endpos]) == seting.end())
                endpos--;
            if(startpos < endpos)    
                swap(s,startpos++,endpos--);    
        }
        return s;
    };
};