class Solution 
{
public:
    int compareVersion(string version1, string version2) 
    {
        int lev1=0,lev2=0;
        int id1=0,id2=0;
        while(id1!=version1.length()||id2!=version2.length()){
            lev1=0;
            while(id1<version1.length()){
                if(version1[id1]=='.'){
                    ++id1;
                    break;
                }
                lev1=lev1*10+(version1[id1]-'0');
                ++id1;
            }
            
            lev2=0;
            while(id2<version2.length()){
                if(version2[id2]=='.'){
                    ++id2;
                    break;
                }
                lev2=lev2*10+(version2[id2]-'0');
                ++id2;
            }
            
            if(lev1>lev2){
                return 1;
            }else if(lev1<lev2){
                return -1;
            }
        }
        return 0;
    }
};