class Solution{
    public:
    int activitySelection(vector<int> start, vector<int> end, int n){
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({end[i],start[i]});
        }
        sort(v.begin(),v.end());
        int ans=1;
        int i=0,j=1;
        while(j<n){
            if(v[j].second > v[i].first){
                ans++;
                i=j;
            }
            j++;
        }
        return ans;
    }
};