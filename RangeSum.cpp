/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
long long S=0;
class Solution {
public:
    
    void getTree( TreeNode *root,int L,int R){
        if(root!=NULL){
            getTree(root->left,L,R);
            if(root->val>=L && root->val<=R)S+=root->val;
            getTree(root->right,L,R);
        }
    } 
        
    int rangeSumBST(TreeNode* root, int L, int R) {
        getTree(root,L,R);
        long long sS=S;
        S=0;
        return sS;
        
        
    }
};