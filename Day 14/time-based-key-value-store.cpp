class TimeMap {
private:
    unordered_map<string,map<int,string>> mp;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(mp[key].empty()) return "";
        
        auto lb = mp[key].lower_bound(timestamp);
        
        if((*lb).first == timestamp){
            return mp[key][timestamp];
        }else{
            if(lb == mp[key].begin()) return "";
            return mp[key][(*(--lb)).first];
        }
    }
};