#include <iostream>
using namespace std;

class Solution 
{
public:
    string convert(string s, int nRows) 
    {
        int strLength = s.length();
        int flag = 0;
        string result(s);

        if(nRows == 1)
            return result;

        for(int  i = 0;i < strLength ; i += 2*nRows-2)
        {
            result[flag] = s[i];
            flag++;
        }

        for (int i = 1; i < nRows -1  ; i ++ )
        {
            int flagM = flag;
            int flagN = flag+1;
            for(int m = i; m < strLength; m += 2*nRows-2)
            {
                result[flagM] = s[m];
                flagM+=2;
                flag++;
            }
            for(int n = i + 2*(nRows - i - 1);n < strLength;n += 2*nRows-2)
            {
                result[flagN] = s[n];
                flagN+=2;
                flag++;
            }
        }

        for(int  i = nRows - 1;i < strLength ; i += 2*nRows-2)
        {
            result[flag] = s[i];
            flag++;
        }
        return result;
    }
};

int main()
{
    Solution sol;
    string s = "PAYPALISHIRING";
    cout << sol.convert(s,3) << endl;
    return 0;
}