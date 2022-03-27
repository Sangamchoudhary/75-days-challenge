class RandomizedSet {
private:
    int n = 0;
    int arr[100001];
    unordered_map<int,int> mp;
public:
    bool insert(int val) {
        if(mp.find(val) != mp.end() and mp[val] != -1) return false;
        arr[n] = val;
        mp[val] = n;
        n++;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end() or mp[val] == -1) return false;
        if(n == 1){ mp[val] = -1; n--; return true;}
        int curr_idx = mp[val];
        mp[val] = -1;
        swap(arr[curr_idx],arr[n]);
        swap(arr[curr_idx],arr[n-1]);
        mp[arr[curr_idx]] = curr_idx;
        n--;
        return true;
    }
    
    int getRandom() {
        if(n == 0) return arr[0];
        int random = rand() % n;
        return arr[random];
    }
};