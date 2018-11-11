class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> mailset;
        for(int i=0;i<emails.size();i++){
            bool beforeAt = true;
            bool afterPlus = false;
            string temp;
            for(int j=0;j<emails[i].size();j++){
                if(emails[i][j] == '@'){
                    temp += emails[i][j];
                    beforeAt = false;
                }
                if(beforeAt && emails[i][j] == '+')
                    afterPlus = true;
                if(beforeAt && !afterPlus && emails[i][j] != '.')
                    temp += emails[i][j];
                if(!beforeAt)
                    temp += emails[i][j];
            }
            mailset.insert(temp);
        }
        return mailset.size();
    }
};
