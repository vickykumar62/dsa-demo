class Solution {
public:

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int pre_start, int pre_end, int in_start, int in_end, unordered_map<int,int>&mpp){

        if(pre_start>pre_end || in_start>in_end) return nullptr;

        TreeNode* root = new TreeNode(preorder[pre_start]);
        int j = mpp[preorder[pre_start]];
        int nums = j-in_start;

        root->left = solve(preorder , inorder , pre_start+1 , pre_start+nums , in_start, j-1 ,mpp);
        root->right = solve(preorder , inorder , pre_start+nums+1 , pre_end , j+1 , in_end , mpp);

        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mpp;
        int n = inorder.size();
        for(int i = 0 ; i < n ; i++){
            mpp[inorder[i]] = i;
        }
        return solve(preorder, inorder , 0 , n-1 , 0 , n-1 , mpp);
    }
};

// Preorder gives root, inorder splits left & right

//  # Recursive logic

// 1. Take preorder[pre_start] as root

// 2. Find root position in inorder using map

// 3. Count nodes in left subtree
//    leftCount = rootIndex - in_start

// 4. Split arrays into:

//    Left subtree
//    Right subtree

// 5. Recursively build left and right trees