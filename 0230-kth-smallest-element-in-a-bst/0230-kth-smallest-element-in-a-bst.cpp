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
vector<int>v;
    int kthSmallest(TreeNode* root, int k) {
        
        if(!root){
            return -1;
        }
        kthSmallest(root->left,k);
        v.push_back(root->val);
        kthSmallest(root->right,k);

      int n = v.size();
      if(k>n){
        return -1;
      }
    return v[k-1];
    }
};