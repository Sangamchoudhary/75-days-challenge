class Solution {
public:
    int maxArea(int h, int v, vector<int>& hc, vector<int>& vc) {
        hc.push_back(0); hc.push_back(h);
        vc.push_back(0); vc.push_back(v);    
        
        sort(hc.begin(),hc.end());
        sort(vc.begin(),vc.end());
        
        int len = 0;
        for(int i=1;i<hc.size();i++){
            len = max(len,hc[i] - hc[i-1]);
        }
        
        int bre = 0;
        for(int i=1;i<vc.size();i++){
            bre = max(bre,vc[i] - vc[i-1]);
        }        
        
        long long mod = 1e9 + 7;
        return ((long long)len * (long long)bre) % mod;
    }
};