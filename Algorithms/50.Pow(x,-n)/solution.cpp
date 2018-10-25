class Solution 
{
public:
    double pow(double x, int n) 
    {
        long long index = n;
        double result = 0;
        int flag = 1;
        if (x<0 && n%2!=0)
            x = -x, flag = -1;
        if (index < 0)
            result = powI(x, -index);
        else
            result = powI(x, index);

        if (index < 0) return 1/result*flag;
        else return result*flag;
    }

    double powI(double x, long long n) // x>0, n>=0
    {
        if (n == 0) 
            return 1;
        else if (n == 1) 
            return x;
        else if (n == 2) 
            return x*x;
        else
        {
            if (n%2==0)
            {
                double mid = powI(x, n/2);
                return mid*mid;
            }
            else {
                double mid = powI(x, (n-1)/2);
                return mid*mid*x;
            }
        }
    }
};