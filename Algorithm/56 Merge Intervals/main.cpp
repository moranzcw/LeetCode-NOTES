#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

 struct Interval 
 {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool cmp(struct Interval in1,struct Interval in2)
{
    return in1.start < in2.start;
}
 
class Solution 
{
public:
    vector<Interval> merge(vector<Interval> &intervals) 
    {
        sort(intervals.begin(),intervals.end(),cmp);
        vector<Interval> result;
        if(intervals.size()==0)
            return result; 
        int pend=intervals[0].end;
        Interval s(intervals[0].start,pend);
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i].start>pend)
            {   
                s.end=pend;
                result.push_back(s);
                s.start=intervals[i].start;
                pend=intervals[i].end;
            }
            else pend=max(intervals[i].end,pend);       
        }
         s.end=pend;
         result.push_back(s);
         return result;
    }
};

int main()
{
    vector<Interval> intervals;
    intervals.push_back(Interval(1,4));
    intervals.push_back(Interval(0,2));
    intervals.push_back(Interval(3,5));
    // intervals.push_back(Interval(3,6));

    Solution sol;
    vector<Interval>result(sol.merge(intervals));
    for (int i = 0; i < result.size(); i++)
    {
        cout<<result[i].start<<" ";
        cout<<result[i].end<<" ";
        cout<<endl;
    }
    return 0;
}