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
int lh(TreeNode* root){
    int h =0;
    while(root){
        h++;
        root=root->left;
    }
    return h;
}

int rh(TreeNode* root){
    int h =0;
    while(root){
        h++;
        root=root->right;
    }
    return h;
}
     int countNodes(TreeNode* root) {
            int cnt =0;

           int left_height =  lh(root);
           int right_height= rh(root);
           
           if(left_height==right_height){
             return (1LL << left_height) - 1;
           }

return 1 + countNodes(root->left) + countNodes(root->right);

     }
};