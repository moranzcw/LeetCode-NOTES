class Solution {
public:
    bool less(string &s1, string &s2, map<char, int> &m){
        int l = min(s1.size(),s2.size());
        for(int i=0;i<l;i++){
            if(m[s1[i]]<m[s2[i]])
                return true;
            if(m[s1[i]]>m[s2[i]])
                return false;
        }
        if(s1.size() <= s2.size())
            return true;
        return false;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        map<char, int> m;
        int i=0;
        for(char &a:order){
            m.insert(pair<char, int>(a,i));
            i++;
        }
        
        for(int i=1;i<words.size();i++){
            if(!less(words[i-1],words[i],m))
                return false;
        }
        return true;
    }
};
