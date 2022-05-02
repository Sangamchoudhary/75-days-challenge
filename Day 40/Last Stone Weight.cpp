class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        multiset<int> arr(stones.begin(),stones.end());
        while(arr.size() > 1){
            auto f = --(--arr.end()); int f_val = *f;
            auto l = --arr.end(); int l_val = *l;
            arr.erase(f); arr.erase(l);
            if(f_val != l_val){
                arr.insert(l_val - f_val);
            }
        }
        if(arr.size()) return *arr.begin();
        return 0;
    }
};