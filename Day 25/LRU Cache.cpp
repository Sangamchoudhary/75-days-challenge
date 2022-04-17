class LRUCache {
private:
    list<int> dll;  
    unordered_map<int,int> mp;
    unordered_map<int,list<int> :: iterator> address;
    int cap;
    
    void move_to_front(int key){
        dll.erase(address[key]);
        dll.push_front(key);    
        address[key] = dll.begin();
    }
    
    void remove_if_exceed(){
        if(dll.size() <= cap) return;
        mp.erase(dll.back());
        address.erase(dll.back());
        dll.pop_back();        
    }
    
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            move_to_front(key);
            return mp[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            mp[key] = value;
            move_to_front(key);
        }else{
            mp[key] = value;
            dll.push_front(key);
            address[key] = dll.begin();
        }  
        remove_if_exceed();
    }
};