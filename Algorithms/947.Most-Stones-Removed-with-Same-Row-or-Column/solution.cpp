class Solution {
public:
    map<int, vector<vector<int> > > xgroup;
    map<int, vector<vector<int> > > ygroup;
    
    int dfs(vector<vector<int>>& stones, vector<bool> &used, vector<int> &p){
        if(xgroup.find(p[0]) != xgroup.end()){
            for(auto i:xgroup.find(p[0])->second){
                if(!used[i[2]]){
                    used[i[2]] = true;
                    dfs(stones, used, i);
                }
            }
        }
        if(ygroup.find(p[1]) != ygroup.end()){
            for(auto i:ygroup.find(p[1])->second){
                if(!used[i[2]]){
                    used[i[2]] = true;
                    dfs(stones, used, i);
                }
            }
        }
        return 0;
    }
    
    int removeStones(vector<vector<int>>& stones) {
        for(int i=0;i<stones.size();i++){
            if(xgroup.find(stones[i][0]) == xgroup.end()){
                xgroup[stones[i][0]] = vector<vector<int> >();
            }
            
            if(ygroup.find(stones[i][1]) == ygroup.end()){
                ygroup[stones[i][1]] = vector<vector<int> >();
            }
            
            vector<int> t = stones[i];
            t.push_back(i);
            xgroup[stones[i][0]].push_back(t);
            ygroup[stones[i][1]].push_back(t);
        }
        
        vector<bool> used(stones.size(),false);
        int count=0;
        for(int i=0;i<stones.size();i++){
            if(used[i])
                continue;
            used[i] = true;
            dfs(stones, used, stones[i]);
            count ++;
        }
        return stones.size() - count;
    }
};
