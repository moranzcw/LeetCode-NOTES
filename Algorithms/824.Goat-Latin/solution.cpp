class Solution {
public:
    string toGoatLatin(string S) {
        string result;
        int i = 0;
        int count = 0;
        bool vowel = false;
        string word;
        while(i<S.size()){
            if(S[i]==' '){
                i++;
                continue;
            }else if(S[i]=='a'||S[i]=='A'||S[i]=='e'||S[i]=='E'||S[i]=='i'
                     ||S[i]=='I'||S[i]=='o'||S[i]=='O'||S[i]=='u'||S[i]=='U'){
                int j=0;
                for(;i+j<S.size();j++)
                    if(S[i+j] == ' ')
                        break;
                word = S.substr(i, j);
                result.append(word);
                result.append("ma");
                result.append(count+1, 'a');
                result.append(1, ' ');
                count += 1;
                i += j;
            }else{
                int j=0;
                for(;i+j<S.size();j++)
                    if(S[i+j] == ' ')
                        break;
                word = S.substr(i+1, j-1);
                result.append(word);
                result.append(1,S[i]);
                result.append("ma");
                result.append(count+1, 'a');
                result.append(1, ' ');
                count += 1;
                i += j;
            }
        }
        return result.substr(0,result.size()-1);
    }
};
