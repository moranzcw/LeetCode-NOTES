class Solution 
{
public:
    //计算一个整数中二进制1的个数
    int numberOf1(int i)
    {
        int count = 0;
        while (i)
        {
            count++;
            i = (i - 1) & i;
        }
        return count;
    }
    
    vector<string> readBinaryWatch(int num) 
    {
        int t = 0;
        string q = to_string(t);
        q += "0";
        cout<<q<<endl;
        
        vector<vector<string> > timeList;
        for(int i=0;i<13;i++)
        {
            vector<string> temp;
            timeList.push_back(temp);
        }
        
        for(int hour=0;hour<12;hour++)
        {
            int ledOfHour = numberOf1(hour);
            for(int minute=0;minute<60;minute++)
            {
                int ledOfMinute = numberOf1(minute);
                string minuteStr = to_string(minute);
                if(minuteStr.size() == 1)
                    minuteStr = "0" + minuteStr;
                    
                string timeStr = to_string(hour) + ":" + minuteStr;
                timeList[ledOfHour + ledOfMinute].push_back(timeStr);
            }    
        }
        return timeList[num];
    }
};