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
TreeNode* preorder(TreeNode* root){
    if(!root){
        return NULL;
    }
    
    TreeNode* leftNode= root->left;
    TreeNode* rightNode= root->right;
    root->left=NULL;
    
    TreeNode* left = preorder(leftNode);
    TreeNode* right = preorder(rightNode);

    root->right = left;

    TreeNode* temp = root;
    while(temp->right){
        temp=temp->right;
    }

    temp->right = right;

return root;
}
    void flatten(TreeNode* root) {
      preorder(root);
    }
};