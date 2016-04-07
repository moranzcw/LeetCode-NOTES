#include <iostream>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

class Solution 
{
private:
    int count[1000];
    int countSize;
    map<string, int> index;
    vector<int> ret;
public:
    vector<int> findSubstring(string S, vector<string> &L) 
    {
        ret.clear();
        if (L.size() == 0)
            return ret;

        index.clear();
        countSize = 0;
        for(int i = 0; i < L.size(); i++)
            if (index.count(L[i]) > 0)
                count[index[L[i]]]++;
            else
            {
                index[L[i]] = countSize;
                count[countSize++] = 1;
            }

            int step = L[0].size();

            vector<int> a;

            for(int i = 0; i < step; i++)
            {
                a.clear();
                for(int j = i; j < S.size(); j += step)
                {
                    if (j + step <= S.size())
                    {
                        string s(S, j, step);
                        if (index.count(s) > 0)
                            a.push_back(index[s]);
                        else
                            a.push_back(-1);
                    }
                }

                int beg = -1;
                int end = 0;
                int size = L.size();
                while(end < a.size())
                {
                    if (a[end] != -1)
                    {
                        if (count[a[end]] > 0)
                        {
                            if (beg == -1)
                                beg = end;
                            size--;
                            count[a[end]]--;
                        }
                        else
                        {
                            while(beg < end)
                            {
                                count[a[beg]]++;
                                size++;
                                if (a[beg++] == a[end])
                                    break;
                            }
                            count[a[end]]--;
                            size--;
                        }
                    }
                    else
                    {
                        size = L.size();
                        if (beg != -1)
                        {    
                            for(int i = beg; i < end; i++)
                                count[a[i]]++;
                        }
                        beg = -1;
                    }

                    end++;

                    if (size == 0)
                    {
                        ret.push_back(beg * step + i);
                        size++;
                        count[a[beg]]++;
                        beg++;
                    }
                }

                if (beg != -1)
                {
                    for(int i = beg; i < end; i++)
                        count[a[i]]++;
                }
            }
            return ret;
    }
};


int main()
{
    vector<string> L;
    L.push_back("a");
    // L.push_back("a");

    Solution sol;
    vector<int> result = sol.findSubstring("a",L);
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }
    cout << endl;
    return 0;
}