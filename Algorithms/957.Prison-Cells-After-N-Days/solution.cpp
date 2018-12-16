class Solution {
public:
    int to_int(vector<int> cells){
        int a = 0;
        for(auto i:cells){
            a = a*2 + i;
        }
        return a;
    }
    
    vector<int> to_cells(int a){
        vector<int> c(8,0);
        for(int i=7;i>=0;i--){
            c[i] = a%2;
            a /= 2;
        }
        return c;
    }

    vector<int> next(vector<int> cells){
        vector<int> n = cells;
        n.front() = 0;
        n.back() = 0;
        for(int i=1;i<7;i++){
            if(cells[i-1] == cells[i+1])
                n[i] = 1;
            else
                n[i] = 0;
        }
        return n;
    }

    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        unordered_map<int, int> m;
        for(int i=0;i<256;i++){
            m.insert(pair<int,int>(i,to_int(next(to_cells(i)))) );
        }
        
        int cycle;
        vector<int> l;
        l.push_back(0);
        for(int i=0;i<256;i++){
            int t = m[l.back()];
            for(int j=0;j<l.size();j++){
                if(l[j] == t){
                    cycle = i-j+1;
                    break;
                }
            }
            l.push_back(t);
        }
        
        N = N % cycle;
        int result = to_int(cells);
        for(int i=0;i<N;i++){
            result = m[result];
        }
        return to_cells(result);
    }
};
