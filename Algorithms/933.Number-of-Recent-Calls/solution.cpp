class RecentCounter {
public:
    vector<int> list;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        list.push_back(t);
        int last = t-3000 > 0? t-3000:0;
        int i=list.size()-1;
        for(;i>=0;i--){
            if(list[i]<last)
                break; 
        }
        return list.size() - i-1;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
