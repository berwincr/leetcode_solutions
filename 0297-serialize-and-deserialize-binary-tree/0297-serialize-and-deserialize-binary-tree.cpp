/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
         string s="";
        if(!root){
            return s;
        }
       
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode* node = q.front();
                q.pop();
                
                if(node==NULL){
                    s+="null,";
                }
                else{
                    s+= to_string(node->val)+",";
                    q.push(node->left);
                    q.push(node->right);
                }

            }
        }
            return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;

        stringstream ss(data);
        string val;

        getline(ss,val,',');

        queue<TreeNode*>q;
        TreeNode* root = new TreeNode(stoi(val));
        q.push(root);

        while(!q.empty()){
           TreeNode* node =q.front();
            q.pop();
            if(!getline(ss,val,',')) break;
            if(val!="null"){
                 node->left = new TreeNode(stoi(val));
                q.push(node->left);
            }
            if(!getline(ss,val,',')) break;
            if(val!="null"){
                node->right = new TreeNode(stoi(val));
                q.push(node->right);
            } 
            }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));