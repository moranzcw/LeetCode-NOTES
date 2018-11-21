class Solution {
public:
    int count_overlap(string &a, string &b){
        int s = min(a.size(),b.size());
        for(int i=s;i>0;i--){
            if(a.substr(a.size()-i) == b.substr(0,i))
                return i;
        }
        return 0;
    }
    
    int search(vector<string>& A, vector<vector<int> > &overlap, vector<bool> &used, int used_count, vector<int> &shortest_super, int &shortest_super_size, vector<int> &cur_super, int cur_super_size){
        // 所有字符串用完，和最短的super比较
        if(used_count == used.size()){
            if(cur_super_size < shortest_super_size){
                shortest_super = cur_super;
                shortest_super_size = cur_super_size;
            }
            return 0;
        }
        
        // 剪枝
        if(cur_super_size >= shortest_super_size)
            return 0;
        
        // 搜索
        for(int i=0;i<A.size();i++){
            if(!used[i]){
                used[i] = true;
                cur_super_size += A[i].size() - overlap[cur_super.back()][i];
                cur_super.push_back(i);
                search(A, overlap, used, used_count+1, shortest_super, shortest_super_size, cur_super, cur_super_size);
                cur_super.pop_back();
                cur_super_size -= A[i].size() - overlap[cur_super.back()][i];
                used[i] = false;
            }
        }
        return 0;
    }
    
    string shortestSuperstring(vector<string>& A) {
        // 计算两两之间的重叠
        vector<vector<int> > overlap(A.size(),vector<int>(A.size()));
        for(int i=0;i<overlap.size();i++){
            for(int j=i+1;j<overlap[0].size();j++){
                overlap[i][j] = count_overlap(A[i],A[j]);
                overlap[j][i] = count_overlap(A[j],A[i]);
            }
        }
        
        // 最短的super，只存下标
        vector<int> shortest_super;
        // 最短的super对应的长度
        int shortest_super_size = INT_MAX;
        // 当前super，只存下标
        vector<int> cur_super;
        // 标记已使用的字符串
        vector<bool> used(A.size(),false);
        
        for(int i=0;i<A.size();i++){
            used[i] = true;
            cur_super.push_back(i);
            search(A, overlap, used, 1, shortest_super, shortest_super_size, cur_super, A[i].size());
            cur_super.pop_back();
            used[i] = false;
        }
        
        // 根据下标，重建字符串
        string shortest = A[shortest_super[0]];
        for(int i=1;i<shortest_super.size();i++){
            shortest += A[shortest_super[i]].substr(overlap[shortest_super[i-1]][shortest_super[i]]);
        }
        return shortest;
    }
};
