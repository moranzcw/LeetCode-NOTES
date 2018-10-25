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
private:
    bool isWordFlag;
    vector<TrieNode*> sonNode;
};

class Trie 
{
public:
    Trie() 
    {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) 
    {
        TrieNode *temp;
        TrieNode *node = root;
        for(int i=0;i<s.size();i++)
        {
            temp = node->findChar(s[i]);
            if(temp == NULL)
                node = node->setChar(s[i]);
            else
                node = temp;
        }
        node->setWordFlag();
    }

    // Returns if the word is in the trie.
    bool search(string key) 
    {
        TrieNode *node = root;
        for(int i=0;i<key.size();i++)
        {
            node = node->findChar(key[i]);
            if(node == NULL)
                return false;
        }
        return node->isWord();
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) 
    {
        TrieNode *node = root;
        for(int i=0;i<prefix.size();i++)
        {
            node = node->findChar(prefix[i]);
            if(node == NULL)
                return false;
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");