class Solution{
    public:
    vector<int> JobScheduling(Job arr[], int n){ 
        int job = 0, profit = 0;
        vector<int> slots(101,-1);
        sort(arr,arr+n,[](Job a,Job b){return a.profit < b.profit;});
        for(int i=n-1;i>=0;i--){
            for(int j=arr[i].dead;j>0;j--){
                if(slots[j] == -1){
                    slots[j] = arr[i].id;
                    job++;
                    profit += arr[i].profit;
                    break;
                }
            }
        }
        return {job,profit};
    } 
};