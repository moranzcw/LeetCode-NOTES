class Solution {
public:
    int minFlipsMonoIncr(string S) {      
        vector<pair<int, int> > group;
        int t;
        int last = S[0]=='1'?1:0;
        group.push_back(pair<int,int>(last, 1));
        for(int i=1;i<S.size();i++){
            t = S[i]=='1'?1:0;
            if(t == last)
                group[group.size()-1].second += 1;
            else
                group.push_back(pair<int,int>(t, 1));
            last = t;
        }

        
        vector<int> leftOne(group.size(),0), rightZero(group.size(),0);
        
        for(int i=1;i<group.size();i++){
            leftOne[i] = group[i-1].first==1?group[i-1].second:0;
            leftOne[i] += leftOne[i-1];
        }
        for(int i=group.size()-2;i>=0;i--){
            rightZero[i] = group[i+1].first==0?group[i+1].second:0;
            rightZero[i] += rightZero[i+1];
        }

        
        int min = S.size();
        for(int i=0;i<group.size();i++)
            if(leftOne[i] + rightZero[i] < min)
                min = leftOne[i] + rightZero[i];
        
        return min;
    }
};
