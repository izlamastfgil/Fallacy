struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    void swap(TreeNode* &arr, TreeNode* &var)
    {
        TreeNode* temp = arr;
        arr = var;
        var = temp;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        
        swap(root->left, root->right);
        
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
        
        return root;
    }
};