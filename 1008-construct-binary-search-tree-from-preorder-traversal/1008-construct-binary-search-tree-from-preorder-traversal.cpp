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
TreeNode* insert(int i,TreeNode* root){
    if(root==NULL){
      return new TreeNode(i);
    }
    if(i<root->val){
        root->left = insert(i,root->left);
    }
    else{
        root->right = insert(i,root->right);
    }


return root;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root= NULL;
        for(int i:preorder){
           root=insert(i,root);
        }
        return root;
    }
};