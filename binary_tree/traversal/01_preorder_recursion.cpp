void preorder(TreeNode* root , vector<int>&ans){
    if(root==nullptr) return;
    ans.push_back(root->val);
    preorder(root->left,ans);
    preorder(root->right,ans);
}