class Solution 
{
public:
    vector<string> fullJustify(vector<string> &words, int L) 
    {
        int start = 0;
        int size = words.size();
        int len = words[0].size();
        vector<string> ans;
        for(int i = 1 ; i < size ; ++i) 
        {
            if(len + words[i].size() + 1 > L) 
            {
                string result = addSpace(words, start , i , len , L);
                ans.push_back(result);
                start = i;
                len = words[i].size();
            } 
            else 
            {
                len += words[i].size() + 1;
            }
        }
        //procee last
        string result = addLast(words, start , size , L);
        ans.push_back(result);
        return ans;
    }
private:
    //[start,end)
    string addSpace(vector<string>& words , int start , int end ,  int len , int L) 
    {
        int exspace = L - len;
        int cnt = end - start;
        string tmp = "";
        if(cnt == 1) 
        {
            tmp = words[start];
            tmp.append(exspace , ' ');
        } 
        else 
        {
            int avespace = exspace / (cnt - 1);
            int reminder = exspace % (cnt - 1);
            for(int i = start ; i < end - 1 ; ++i) 
            {
                tmp += words[i];
                tmp.append(avespace + 1 , ' ');
                if(reminder) 
                {
                    tmp.append(1 , ' ');
                    reminder --;
                }
            }
            tmp += words[end-1];
        }
        return tmp;
    }
    string addLast(vector<string>& words , int start , int end , int L) 
    {
        string tmp = words[start];
        for(int i = start + 1 ; i < end ; ++i) 
        {
            tmp += " " + words[i];
        }
        if(tmp.size() < L) tmp.append(L - tmp.size() , ' ');
        return tmp;
    }
};