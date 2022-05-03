class Solution{
    public:
    int maxMeetings(int start[], int end[], int n){
        vector<pair<int,int>> vp;
        for(int i=0;i<n;i++){
            vp.push_back({start[i],end[i]});
        }
        sort(vp.begin(),vp.end(),[&](auto &a,auto &b){return a.second < b.second;});
        int en_time = -1;
        int ans = 0;
        for(auto it : vp){
            if(en_time < it.first){
                en_time = it.second;
                ans++;
            }else{
                en_time = min(en_time,it.second);
            }
        }
        return ans;
    }
};