class Solution 
{
public:
    vector<string> strList1 = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    vector<string> strList2 = {"Zero","Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    vector<string> strList3 = {""," Thousand"," Million"," Billion"};
    
    string translate(int num)
    {
        if(num == 0)
            return "";
        string result;
        int hundred = num/100;
        int decade = (num%100)/10;
        int unit = num%10;

        if(hundred != 0)
            result += strList1[hundred] + " Hundred";
        
        num %= 100;
        if(num>0)
        {
            if(hundred != 0)
                result += " ";
                
            if(num<20)
                result += strList1[num];
            else
            {
                result += strList2[decade];
                if(unit != 0)
                    result += " " + strList1[unit];
            }
        }
        return result;
    }
    string numberToWords(int num) 
    {
        if(num == 0)
            return "Zero";
            
        string result;
        int temp;
        int base = 1000000000;
        for(int i = 3;i>=0;i--)
        {
            temp = (num/base)%1000;
            if(temp !=0)
            {
                if(result.size() != 0)
                    result += " ";
                result += translate(temp) + strList3[i];
            }
            base /= 1000;
        }
        return result;
    }
};