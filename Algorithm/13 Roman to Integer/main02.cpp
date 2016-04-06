#include <iostream>
#include <map>
using namespace std;

class Solution 
{
public:
    int romanToInt(string s) 
    {
        int map[26];
        map['I'-'A'] = 1;
        map['V'-'A'] = 5;
        map['X'-'A'] = 10;
        map['L'-'A'] = 50; 
        map['C'-'A'] = 100;
        map['D'-'A'] = 500;
        map['M'-'A'] = 1000;

        int result = 0, n = s.size();
        s.push_back(s[n-1]);
        for(int i = 0; i < n; i++)
        {
            if(map[s[i]-'A'] >= map[s[i+1]-'A'])
                result += map[s[i]-'A'];
            else result -= map[s[i]-'A'];
        }
        return result;
    }
};

int main()
{
    Solution sol;

    cout << sol.romanToInt("MCCXXXIV") <<endl;
    cout << sol.romanToInt("MMMCDXXI") <<endl;
    return 0;
}