void postorder(TreeNode* root , vector<int>&ans){
    if(root==nullptr) return;
    postorder(root->left,ans);
    postorder(root->right,ans);
    ans.push_back(root->val);
}