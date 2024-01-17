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
int linearSearch(vector<int> arr, int x)
{
    for(int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == x)
            return i;
    }
    return 0;
}

TreeNode* helper(vector<int> &inorder, vector<int> &postorder, int instart, int inend, int poststart, int postend)
{
    if (instart > inend || poststart > postend) {
            return nullptr; 
        }
    int root = postorder[postend];
    int rootInInorder = linearSearch(inorder, root);
    int leftArrSize = rootInInorder - instart;
    TreeNode* newNode = new TreeNode (root);

    newNode->left = helper(inorder, postorder, instart, rootInInorder - 1, poststart, poststart + leftArrSize - 1);
    newNode->right = helper(inorder, postorder, rootInInorder + 1, inend, poststart + leftArrSize, postend - 1);

    return newNode;
}

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty())
            return nullptr;
        
        return helper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);

    }
};