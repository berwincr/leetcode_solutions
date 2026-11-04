/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

int preIndex=0;

TreeNode* construct(vector<int>& preorder, vector<int>& inorder, int start, int end,unordered_map<int,int>& mp){
    
        if (start > end)
            return NULL;

        int rootVal = preorder[preIndex++];

        TreeNode* root = new TreeNode(rootVal);

        int mid = mp[rootVal];

        root->left = construct(preorder, inorder, start, mid - 1, mp);

        root->right = construct(preorder, inorder, mid + 1, end, mp);

        return root;

}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;

        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return construct(preorder, inorder, 0, inorder.size() - 1, mp);
    }
};