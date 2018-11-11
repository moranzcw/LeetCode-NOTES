class Solution {
public:
    bool validPalindrome(string s) {
        bool skipFlag = true;
        bool result = true;
        for(int cur1=0, cur2=s.size()-1; cur1 < cur2; cur1++,cur2--){
            if(s[cur1] != s[cur2]){
                if(skipFlag && s[cur1+1] == s[cur2]){
                    cur1 ++;
                    skipFlag = false;
                }
                else{
                    result = false;
                    break;
                }
            }
        }
        if(result)
            return result;
        
        skipFlag = true;
        result = true;
        for(int cur1=0, cur2=s.size()-1; cur1 < cur2; cur1++,cur2--){
            if(s[cur1] != s[cur2]){
                if(skipFlag && s[cur1] == s[cur2-1]){
                    cur2 --;
                    skipFlag = false;
                }
                else{
                    result = false;
                    break;
                }
            }
        }
        return result;
    }
};
