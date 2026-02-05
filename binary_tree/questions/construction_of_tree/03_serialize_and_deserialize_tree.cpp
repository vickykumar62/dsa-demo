class Codec {
public:

    // ----------- SERIALIZE -----------
    // Preorder traversal: Root → Left → Right
    void preorder(TreeNode* root, string &ans) {

        // If node is null, store marker and return
        if (root == nullptr) {
            ans += "#,";
            return;
        }

        // Store current node value
        ans += to_string(root->val) + ",";

        // Serialize left subtree
        preorder(root->left, ans);

        // Serialize right subtree
        preorder(root->right, ans);
    }

    // Converts tree to string
    string serialize(TreeNode* root) {
        string ans = "";
        preorder(root, ans);
        return ans;
    }


    // ----------- DESERIALIZE -----------

    // Builds tree from preorder list
    TreeNode* buildTree(vector<string>& nodes, int &i) {

        // If marker found, this node is null
        if (nodes[i] == "#") {
            i++;                // move to next value
            return nullptr;
        }

        // Create node from current value
        TreeNode* root = new TreeNode(stoi(nodes[i]));
        i++;                    // move index forward

        // Build left subtree
        root->left = buildTree(nodes, i);

        // Build right subtree
        root->right = buildTree(nodes, i);

        return root;
    }

    // Converts string back to tree
    TreeNode* deserialize(string data) {

        // Split string by comma
        vector<string> nodes;
        string temp = "";

        for (char c : data) {
            if (c == ',') {
                nodes.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }

        int i = 0;  // index for preorder traversal
        return buildTree(nodes, i);
    }
};

Serialize

Visit node

Save its value

Go left

Go right

If node is missing → save #

Deserialize

Read values in same preorder order

# means → stop and return NULL

Create node, then build left and right recursively