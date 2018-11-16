class Solution {
public:
    int get_gcd(int a, int b) {
        int h = max(a, b);
        int l = min(a, b);
        
        if (l == 0) return h;
        
        int m = h % l;
        
        while (m) {
            h = l;
            l = m;
            m = h % l;
        }
        return l;
    }
    
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int, int> count;
        
        for(auto i:deck){
            if(count.find(i) != count.end())
                count[i] += 1;
            else
                count[i] = 1;
        }
        
        int min_gcd = count.begin()->second;
        int last = min_gcd;
        for(auto i=count.begin();i!=count.end();i++){
            min_gcd = min(min_gcd, get_gcd(i->second,last));
            last = i->second;
        }
        return min_gcd>=2;
    }
};
