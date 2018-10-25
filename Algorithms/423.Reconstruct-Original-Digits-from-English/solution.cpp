class Solution 
{
public:
    string originalDigits(string s) 
    {
        vector<int> countLetter(26,0);
        for(int i=0;i<s.size();i++)
            countLetter[s[i]-'a']++;
        vector<int> countNum(10,0);
        countNum[0] = countLetter['z'-'a'];
        countNum[2] = countLetter['w'-'a'];
        countNum[4] = countLetter['u'-'a'];
        countNum[6] = countLetter['x'-'a'];
        countNum[8] = countLetter['g'-'a'];
        countNum[1] = countLetter['o'-'a']-countNum[0]-countNum[2]-countNum[4];
        countNum[3] = countLetter['h'-'a']-countNum[8];
        countNum[5] = countLetter['f'-'a']-countNum[4];
        countNum[7] = countLetter['v'-'a']-countNum[5];
        countNum[9] = (countLetter['n'-'a']-countNum[1]-countNum[7])/2;
        
        string result;
        for(int i=0;i<countNum.size();i++)
            for(int j=0;j<countNum[i];j++)
                result += i +'0';
        return result;
    }
};