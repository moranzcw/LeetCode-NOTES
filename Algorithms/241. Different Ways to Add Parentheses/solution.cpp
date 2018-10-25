class Solution
{
public:
    vector<int> diffWaysToCompute(string input)
    {
        vector<int> num; //数字
        vector<char> sign; //操作符
        int tempNumber=0;
        int len=input.size();
        for(int i=0;i<len;)
        {
            if(input[i]>='0'&&input[i]<='9') //数字
            {
                // 提取字符串里的数字
                tempNumber=0;
                while(i<len&&input[i]>='0'&&input[i]<='9')
                {
                    tempNumber = tempNumber*10 + input[i]-'0';
                    i++;
                }
                num.push_back(tempNumber);
            }
            else if(input[i]==' ')
                i++;
            else
            {
                // 提取操作符
                sign.push_back(input[i]);
                i++;
            }
        }
        
        int numSum = num.size();
        vector<int> res;
        vector<vector<multiset<int> > > temp;
        multiset<int> tempSet;
        vector<multiset<int> >temVec;
        for(int i=0; i<numSum; ++i)
            temVec.push_back(tempSet);
        for(int i=0; i<numSum; ++i)
            temp.push_back(temVec);
        for(int i=0; i<numSum; ++i)
            temp[i][i].insert(num[i]);
        for(int i=1; i<numSum; ++i)
        {
            if(sign[i-1]=='+')
                temp[i-1][i].insert(num[i-1]+num[i]);
            else if(sign[i-1]=='-')
                temp[i-1][i].insert(num[i-1]-num[i]);
            else
                temp[i-1][i].insert(num[i-1]*num[i]);
        }
        for(int i=2; i<numSum; ++i)
        {
            for(int j=0; j+i<numSum; ++j)
            {
                multiset<int>::iterator ite=temp[j][j].begin();
                for(multiset<int>::iterator ite2=temp[j+1][i+j].begin(); ite2!=temp[j+1][i+j].end(); ++ite2)
                {
                    if(sign[j]=='+')
                        temp[j][i+j].insert(*ite+(*ite2));
                    else if(sign[j]=='-')
                        temp[j][i+j].insert(*ite-(*ite2));
                    else
                        temp[j][i+j].insert(*ite*(*ite2));
                    }
                ite=temp[i+j][i+j].begin();
                for(multiset<int>::iterator ite2=temp[j][i+j-1].begin(); ite2!=temp[j][i+j-1].end(); ++ite2)
                {
                    if(sign[i+j-1]=='+')
                        temp[j][i+j].insert(*ite2+(*ite));
                    else if(sign[j+i-1]=='-')
                        temp[j][i+j].insert(*ite2-(*ite));
                    else
                        temp[j][i+j].insert(*ite2*(*ite));
                    }
                for(int k=j+1; k<i+j-1; ++k)
                {
                    for(multiset<int>::iterator ite2=temp[j][k].begin(); ite2!=temp[j][k].end(); ++ite2)
                    {
                        for(multiset<int>::iterator ite3=temp[k+1][j+i].begin(); ite3!=temp[k+1][j+i].end(); ++ite3)
                        {
                            if(sign[k]=='+')
                                temp[j][i+j].insert(*ite2+(*ite3));
                            else if(sign[k]=='-')
                                temp[j][i+j].insert(*ite2-(*ite3));
                            else
                                temp[j][i+j].insert(*ite2*(*ite3));
                            }
                    }
                }
            }
        }
        for(multiset<int>::iterator ite2=temp[0][numSum-1].begin();ite2!=temp[0][numSum-1].end();++ite2)
            res.push_back(*ite2);
        return res;
    }
};