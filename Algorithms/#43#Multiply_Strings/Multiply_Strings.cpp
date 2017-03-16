#include <iostream>
using namespace std;

class Solution 
{
public:
    string multiply(string num1, string num2) 
    {
        int len1 = num1.size(), 
            len2 = num2.size(), 
            len = len1 + len2;
        string str(len, '0');
        for (int i = len1 - 1; i >= 0; i--)
        {
            int a = num1[i] - '0';
            for (int j = len2 - 1, k = len2 + i; j >= 0; j--, k--)
            {
                int b = num2[j] - '0';
                int c = str[k] - '0';
                int t = b * a + c;
                str[k] = t % 10 + '0';
                int d = (str[k-1] - '0') + t / 10;
                if (d >= 10)
                    str[k-2] = str[k-2] - '0' + d / 10 + '0';
                str[k-1] = d % 10 + '0';
            }
        }
        int x = 0;
        while (str[x] == '0')
            x++;
        if (str.substr(x, len - x) == "")
            return "0";
        return str.substr(x, len - x);
    }
};

int main()
{
    Solution sol;
    cout<<sol.multiply("498828660196","840477629533")<<endl;
    return 0;
}