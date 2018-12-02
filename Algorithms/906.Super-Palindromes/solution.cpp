class Solution {
public:
    bool larger(string a, string b){
        if(a.size() < b.size())
            return false;
        if(a.size() > b.size())
            return true;
        for(int i = 0; i < a.size(); i++){
            if(a[i] != b[i]) {
                return a[i] > b[i];
            }
        }
        return false;
    }
    
    string square(string input){
        // 平方
        long long temp = stoll(input);
        long long result = temp*temp;
        return to_string(result);
    }
    bool isPar(string input){
        // 回文        
        for(int l=0, r=input.size()-1;l<=r;l++,r--){
            if(input[l] != input[r])
                return false;
        }
        return true;
    }
    
    int superpalindromesInRange(string L, string R) {
        int n = R.size();
        vector<vector<string>> pool; // 按相同位数存储回文串
        for(int i=0; i<n/2+1; i++){
            vector<string> cur;
            if(i == 0){
                cur = {"0", "1", "2", "3", "4", "5", "6", "7","8", "9"};
            }else if(i == 1){
                cur = {"00", "11", "22", "33", "44", "55", "66", "77", "88", "99"};
            }else{
                vector<string> &prev = pool[i-2];
                for(auto &p:prev){
                    for(auto &dig:pool[0]){
                        cur.push_back(dig + p + dig);
                    }
                }
            }
            pool.push_back(cur);
        }
        
        // 统计符合条件的super
        int count = 0;
        for(auto &strs:pool){
            for(auto &str:strs){
                string super = square(str);
                if(isPar(super) && (larger(super, L) || super == L ) && (larger(R, super) || super == R ) ){
                    count ++;
                }
            }
        }
        return count;
    }
    
    
};
