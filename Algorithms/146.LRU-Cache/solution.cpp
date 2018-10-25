struct CacheNode
{
    int key;
    int value;
    CacheNode(int k , int v) : key(k) , value(v){}
};

class LRUCache
{
public:
    LRUCache(int capacity) 
    {
        size = capacity;
    }
    
    int get(int key) 
    {
        if(cacheMap.find(key) != cacheMap.end())
        {
           auto it = cacheMap[key];
           cacheList.splice(cacheList.begin() , cacheList , it);
           cacheMap[key] = cacheList.begin();
           return cacheList.begin()->value;
        }
        else
        {
            return -1;
        }
    }
    
    void set(int key, int value) 
    {
        if (cacheMap.find(key) == cacheMap.end())
        {
            if(cacheList.size() == size)
            {
                cacheMap.erase(cacheList.back().key);
                cacheList.pop_back();
            }
            cacheList.push_front(CacheNode(key , value));
            cacheMap[key] = cacheList.begin();
        }
        else
        {
           auto it = cacheMap[key];
           cacheList.splice(cacheList.begin() , cacheList , it);
           cacheMap[key] = cacheList.begin();
           cacheList.begin()->value = value;
        }
    }
private:
    int size;
    list<CacheNode> cacheList;
    unordered_map<int , list<CacheNode>::iterator > cacheMap;
};