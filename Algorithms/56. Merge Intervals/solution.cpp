/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
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