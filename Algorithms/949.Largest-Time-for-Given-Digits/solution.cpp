class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        vector<bool> used(4,false);
        vector<int> result;
        for(int i=0;i<A.size();i++){
            if(A[i]<0 || A[i]>2)
                continue;
            int t1 = A[i];
            used[i] = true;
            for(int j=0;j<A.size();j++){
                if(used[j] || (t1==2 && (A[j]>3 || A[j]<0) ) )
                    continue;
                int t2 = t1*10 + A[j];
                used[j] = true;
                for(int k=0;k<A.size();k++){
                    if(used[k] || A[k]>5 || A[k]<0)
                        continue;
                    int t3 = t2*10 + A[k];
                    used[k] = true;
                    for(int y=0;y<A.size();y++){
                        if(used[y])
                            continue;
                        result.push_back(t3*10+A[y]);
                        // cout<<t3*10+A[y]<<endl;
                    }
                    used[k] = false;
                }
                used[j] = false;
            }
            used[i] = false;
        }
        
        if(result.empty())
            return "";
        
        vector<int>::iterator it = max_element(result.begin(), result.end());
        string r = to_string(*it);
        if(r.size()<4)
            r = string(4-r.size(),'0') + r;
        
        return r.substr(0,2) + ":" + r.substr(2);
    }
};
