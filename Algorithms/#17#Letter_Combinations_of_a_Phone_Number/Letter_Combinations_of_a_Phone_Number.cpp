#include <iostream>
#include <vector>
using namespace std;

char m[10][5] = {" ","", "abc","def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
class Solution 
{
public:
    vector<string> res;
    int len;
    vector<string> letterCombinations(string digits) 
    {
        if(digits.size() == 0)
            return res;
        len = digits.size();
        char *c = new char[len+1];
        c[len] = '\0';
        res.clear();
        gen(digits, 0, c);
        return res;
    }
    
    void gen(const string& num, int cur, char *c) 
    {
        if (cur == len) {
            res.push_back(c);
            return;
        }
        char *s = &(m[num[cur] - '0'][0]);
        while (*s != '\0') {
            c[cur] = *s;
            gen(num, cur+1, c);
            s++;
        }
    }
};

int main()
{
    Solution sol;
    vector<string> result = sol.letterCombinations("");
    for(int i = 0;i<result.size();i++)
        cout<<result[i]<<endl;
    cout<<endl;
    return 0;
}