class TrieNode 
{
public:
    // Initialize your data structure here.
    TrieNode()
    {
        sonNode.resize(26,NULL);
        isWordFlag = false;
    }

    TrieNode* findChar(char c)
    {
        return sonNode[c-'a'];
    }

    TrieNode* setChar(char c)
    {
        sonNode[c-'a'] = new TrieNode();
        return sonNode[c-'a'];
    }
    
    void setWordFlag()
    {
        isWordFlag = true;
    }

    bool isWord()
    {
        return isWordFlag;
    }
     
     TrieNode* findSon(int n)
    {
        return sonNode[n];
    }

private:
    bool isWordFlag;
    vector<TrieNode*> sonNode;
};

class WordDictionary 
{
public:
    WordDictionary() 
    {
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word) 
    {
        TrieNode *temp;
        TrieNode *node = root;
        for(int i=0;i<word.size();i++)
        {
            temp = node->findChar(word[i]);
            if(temp == NULL)
            {
                node = node->setChar(word[i]);
            }
            else
                node = temp;
        }
        node->setWordFlag();
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) 
    {
        return searchByBackTracking(root,word,0);
    }

    bool searchByBackTracking(TrieNode *node, const string &word, int n)
    {
        if(node == NULL)
            return false;

        if(n == word.size())
            return node->isWord();
        bool result = false;
        if(word[n] == '.')
        {
            for(int i=0;i<26;i++)
            {
                result = result || searchByBackTracking(node->findSon(i),word,n+1);
            }
        }
        else
        {
            result = result || searchByBackTracking(node->findChar(word[n]),word,n+1);
        }
        return result;
    }

private:
    TrieNode* root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");