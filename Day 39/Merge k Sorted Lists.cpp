#define pii pair<int,ListNode*>
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists){
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        
        for(auto &it : lists) 
            if(it) pq.push({it->val,it});
        
        if(pq.empty()) return NULL;
        
        ListNode* temp;
        ListNode* ansHead = pq.top().second;
        
        while(pq.size()){
            temp = pq.top().second; pq.pop();
            
            if(temp->next) pq.push({temp->next->val,temp->next});
            
            if(pq.size()) temp->next = pq.top().second;
        }
        
        return ansHead;
    }
};