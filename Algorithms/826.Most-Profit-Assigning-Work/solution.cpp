bool cmp(pair<int,int> i, pair<int,int> j){
    return i.first < j.first;
}

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int> > prolist(difficulty.size());
        for(int i=0;i<difficulty.size();i++){
            prolist[i].first = difficulty[i];
            prolist[i].second = profit[i];
        }
        
        sort(prolist.begin(),prolist.end(),cmp);
        
        // vector<int> pro(profit.size());
        int maxpro = 0;
        for(int i=0;i<profit.size();i++){
            maxpro = max(maxpro,prolist[i].second);
            prolist[i].second = maxpro;
        }
        int result = 0;
        int temppro = 0;
        for(int i=0;i<worker.size();i++){
            temppro = 0;
            for(int j=0;j<difficulty.size();j++){
                if(worker[i] >= prolist[j].first)
                    temppro = prolist[j].second;
                else
                    break;
            }
            result += temppro;
        }
        return result;
    }
};
