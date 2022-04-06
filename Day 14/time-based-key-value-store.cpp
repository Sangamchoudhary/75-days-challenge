class TimeMap {
public:
    unordered_map<string,map<int,string>>m;
    TimeMap() {
        m.clear();
    }
    
    void set(string key, string value, int timestamp) {
        m[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
        if(m.find(key)==m.end())
        {
            return "";
        }
        if(m[key].find(timestamp)!=m[key].end())
        {
            return m[key][timestamp];
        }
        auto it=m[key].lower_bound(timestamp);
        if(it==m[key].begin())
        {
            return "";
        }
        it--;
        return it->second;
    }
};
