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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        TreeNode * node=new TreeNode(val);
        TreeNode *p=root;
        if(root==NULL)return node; // No tree present 
        
        while(p!=NULL){
            if(p->val>=val){
                if(p->left==NULL){
                    p->left=node;
                    return root;
                }
                p=p->left;
            }
            else{
                
                if(p->right==NULL){
                    p->right=node;
                    return root;
                }
                p=p->right;
                
                
            }
            
        }
        
        return root;
        
    }
};