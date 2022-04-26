int Ceil(node* root, int input){
    if (root == NULL)
        return -1;
        
    if (root->key == input)
        return root->key;
        
    if (root->key < input)
        return Ceil(root->right, input);
        
    int ceil = Ceil(root->left, input);
    return (ceil >= input) ? ceil : root->key;
}

void floorCeilBSTHelper(Node* root, int key, int& floor, int& ceil){
    while (root) {
 
        if (root->data == key) {
            ceil = root->data;
            floor = root->data;
            return;
        }
 
        if (key > root->data) {
            floor = root->data;
            root = root->right;
        }
        else {
            ceil = root->data;
            root = root->left;
        }
    }
    return;
}