class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        vector<pair<char, int> > na, ty;
        char last='0';
        for(int i=0;i<name.size();i++){
            if(name[i] == last)
                na[na.size()-1].second += 1;
            else
                na.push_back(pair<char, int>(name[i], 1));
            last = name[i];
        }
        
        last='0';
        for(int i=0;i<typed.size();i++){
            if(typed[i] == last)
                ty[ty.size()-1].second += 1;
            else
                ty.push_back(pair<char, int>(typed[i], 1));
            last = typed[i];
        }
        
        if(na.size() != ty.size())
            return false;
        for(int i=0;i<na.size();i++){
            if( (na[i].first != ty[i].first) || (na[i].second > ty[i].second))
                return false;
        }
        return true;
    }
};
