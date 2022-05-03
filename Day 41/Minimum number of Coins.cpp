class Solution{
public:
    vector<int> minPartition(int N){
        vector<int> coins = {1,2,5,10,20,50,100,200,500,2000};
        vector<int> ans;
        int sz = coins.size();
        for(int i=sz-1;i>=0;i--){
            int req = (N/coins[i]);
            N -= (req * coins[i]);
            while(req--) ans.push_back(coins[i]);
        }
        return ans;
    }
};