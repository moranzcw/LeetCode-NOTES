class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        return Helper(numerator, denominator);
    }
    string Helper(long long numerator, long long denominator)
    {
        //convert to 64_int in case INT_MIN/-1 overflow
        
        //special case
        if(denominator == 0)
            return "";
        else if(numerator == 0)
            return "0";
        
        string ret = "";
        
        if((numerator<0) ^ (denominator<0))
        {//one of them is negative, with bit or
            ret += '-';
            numerator = abs(numerator);
            denominator = abs(denominator);
        }
        
        //integer part
        if(numerator/denominator == 0)
        //integer part is 0
            ret += '0';
        else
        {
            long long quotient = numerator/denominator;
            ret += std::to_string(quotient);
            if(numerator%denominator == 0)
            //divisible
                return ret;
            else
            //not divisible, numerator as remainder 
                numerator -= (quotient*denominator);
        }
        
        //decimal part
        ret += '.';
        string demical;
        map<long long, int> m;    //<remainder, index> pair
        long long r = numerator;
        while(r)
        {
            if(m.find(r) != m.end())
            {//remainder
                ret.insert(m[r], 1, '(');   //insert (iterator p, size_t n, char c);
                ret += ')';
                break;    
            }
            m[r] = ret.size();
            r *= 10;    //next digit
            ret += std::to_string(r/denominator);
            r %= denominator;
        }
        return ret;
    }
};