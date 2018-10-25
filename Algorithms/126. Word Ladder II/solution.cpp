class Solution 
{
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) 
    {
          vector<vector<string> >ans;
          if(start == end) 
            return ans;
          unordered_set<string>current , next;
          unordered_set<string> flag;
          unordered_map<string,vector<string> > father;
          
          current.insert(start);

          bool found = false;
         
          while(!current.empty() && !found) 
          {
              for(const auto &x : current) 
              {
                  flag.insert(x);
              }
              
              for(auto x : current) 
              {
                  for(int i = 0 ; i < x.size() ; ++i) 
                  {
                      for(int j = 'a' ; j <= 'z' ; ++j) 
                      {
                          if(x[i] == j) continue;
                          string tmp = x;
                          tmp[i] = j;
                          if(tmp == end) found = true;
                          if(dict.find(tmp) != dict.end() && flag.find(tmp) == flag.end()) 
                          {
                              next.insert(tmp);
                              father[tmp].push_back(x);
                          }
                     }
                  }
              }
              
              current.clear();
              swap(current, next);
          }
          
          if(found) 
          {
              vector<string> c;
              dfs(ans , father , c , start , end);
          }
          return ans;
    }
private:
    void dfs(vector<vector<string> >&ans, 
             unordered_map<string,vector<string> >& father ,
             vector<string>& c , 
             string& start ,
             string& now) 
    {
                 
        c.push_back(now);
        if(now == start) 
        {
            ans.push_back(c);
            reverse(ans.back().begin() , ans.back().end());
            c.pop_back();
            return;
        }
        auto que = father.find(now) -> second;
        for(auto& x : que) 
        {
            dfs(ans , father , c , start , x);
        }
        c.pop_back();
    }
};