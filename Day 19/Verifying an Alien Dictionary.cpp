class Solution {
private:
    unordered_map<char, char> mp;
public:
    bool isAlienSorted(vector<string>& words, string order) { 
        for(int i = 0; i < size(order); i++) mp[order[i]] = i + 'a';  
        for(auto& word : words)
            for(auto& c : word) c = mp[c];
        return is_sorted(begin(words), end(words));
    } 
};

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> mp;
        for(int i=0;i<order.size();i++) mp[order[i]] = i;
        
        for(int i=0;i<words.size()-1;i++){
            bool flag = true;
            int mini = min(words[i].size(),words[i+1].size());
            int j;
            for(j=0;j<mini;j++){
                if(mp[words[i][j]] < mp[words[i+1][j]]) {flag=false;break;}
                else if(mp[words[i][j]] == mp[words[i+1][j]]) continue;
                else return false;
            }
            if(flag and j < words[i].size()) return false;
        }
        
        return true;
    }
};