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
TreeNode* findMax(TreeNode* root){
    if(!root){
        return NULL;
    }
    TreeNode* curr = root;
    while(curr->right){
        curr=curr->right;
    }
    return curr;
}
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root){
            return NULL;
        }

        if(key<root->val){
            root->left = deleteNode(root->left,key);
        }
        else if(key > root->val){
            root->right = deleteNode(root->right , key);
        }
        else{
            if(!root->left && !root->right){
                return NULL;
            }
            else if(root->left && root->right){
                TreeNode* temp = findMax(root->left);
                root->val = temp->val;
                root->left = deleteNode(root->left,temp->val);
            }
            else{
                return root->left?root->left:root->right;
            }
        }
        return root;
    }
};