void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if(!root) 
    return;
    findPreSuc(root->left , pre, suc, key);
    if(root->key<key)         
    pre = root;
    if(root->key>key && !suc) 
    suc = root;
    findPreSuc(root->right, pre, suc, key);
}
