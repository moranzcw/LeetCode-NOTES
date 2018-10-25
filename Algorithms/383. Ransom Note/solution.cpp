class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        int table[256];
        for(int i=0;i<256;i++)
            table[i] = 0;
        for(int i=0;i<ransomNote.size();i++)
            table[ransomNote[i]]--;
        for(int i=0;i<magazine.size();i++)
            table[magazine[i]]++;
        for(int i=0;i<256;i++)
            if(table[i] < 0)
                return false;
        return true;
    }
};