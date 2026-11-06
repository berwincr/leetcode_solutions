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
TreeNode* construct(vector<int>& inorder, vector<int>& postorder, unordered_map<int,int>&mp , int start, int end, int& p ){
   if(start>end){
    return NULL;
   }

   int val = postorder[p];
   p--;

   TreeNode* root = new TreeNode(val);
   int mid = mp[val];

   root->right = construct(inorder,postorder,mp,mid+1,end,p);
   root->left = construct(inorder,postorder,mp,start,mid-1,p);

    return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mp;

        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int postIndex = postorder.size()-1;

        return construct(inorder,postorder,mp,0,inorder.size()-1,postIndex);
    }
};