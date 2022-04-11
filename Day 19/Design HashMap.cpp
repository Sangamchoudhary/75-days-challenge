class MyHashMap {
private:
    int sz;
    vector<list<pair<int,int>>> arr;
public:
    MyHashMap() { 
        sz = 11;
        arr.resize(sz);
    }
    
    int hash(int key){
        return key % sz;
    }
    
    list<pair<int,int>> :: iterator search(int key){
        int i = hash(key);
        list<pair<int,int>> :: iterator it = arr[i].begin();
        while(it != arr[i].end()){
            if(it->first == key) return it;
            it++;
        }
        return it;
    }
    
    void put(int key, int value) {
        int i = hash(key);
        auto pos = search(key);
        if(pos == arr[i].end()) arr[i].push_back({key,value});
        else pos->second = value;
    }
    
    int get(int key) {
        int i = hash(key);
        auto pos = search(key);
        if(pos == arr[i].end()) return -1;
        return pos->second;
    }
    
    void remove(int key) {
        int i = hash(key);
        auto pos = search(key);
        if(pos == arr[i].end()) return;
        arr[i].erase(pos);
    }
};
