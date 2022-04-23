class Codec {
public:
    string serialize(TreeNode* root) {
        if(!root) return "";
        string encode;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            int sz = q.size();
            while(sz--){
                auto top = q.front(); q.pop();
                
                if(!top){
                    encode.append("#,");
                }else{
                    encode.append(to_string(top->val) + ',');
                }
                
                if(top){
                    q.push(top->left);
                    q.push(top->right);
                }
            }
        }
        cout<<encode;
        return encode;
    }

    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            int sz = q.size();
            while(sz--){
                auto top = q.front(); q.pop();
                
                getline(s,str,',');
                if(str == "#"){
                    top->left = NULL;
                }else{
                    top->left = new TreeNode(stoi(str));
                    q.push(top->left);
                }
                
                getline(s,str,',');
                if(str == "#"){
                    top->right = NULL;
                }else{
                    top->right = new TreeNode(stoi(str));
                    q.push(top->right);
                }
            }
        }
        return root;
    }
};