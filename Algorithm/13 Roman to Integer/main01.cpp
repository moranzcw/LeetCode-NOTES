#include <iostream>
#include <map>
using namespace std;

class Solution 
{
public:
    int romanToInt(string s) 
    {
        map<char, int> dct;
        dct['I'] = 1, dct['i'] = 1;
        dct['V'] = 5, dct['v'] = 5;
        dct['X'] = 10, dct['x'] = 10;
        dct['L'] = 50, dct['l'] = 50;
        dct['C'] = 100, dct['c'] = 100;
        dct['D'] = 500, dct['d'] = 500;
        dct['M'] = 1000, dct['m'] = 1000;

        int sum = 0, j;
        for(int i = 0; i < s.size(); ++i)
        {
            j = i+1;
            if(j < s.size() && dct[s[j]] > dct[s[i]])
            {
                sum += dct[s[j]] - dct[s[i]];
                i = j;
            }
            else
                sum += dct[s[i]];
        }
        return sum;
    }
};

int main()
{
    Solution sol;

    cout << sol.romanToInt("MCCXXXIV") <<endl;
    cout << sol.romanToInt("MMMCDXXI") <<endl;
    return 0;
}