/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    
    
    bool checkUnival(TreeNode  * root,int &count){
    if(root==NULL)return true;
    bool left=checkUnival(root->left,count);
    bool right=checkUnival(root->right,count);
    
    if(left==false || right==false)return false;
    
    if(root->left!=NULL && root->left->val!=root->val)return false;
    if(root->right!=NULL && root->right->val!=root->val)return false;
    
    count++;
    return true;
    
    
    }

    bool isUnivalTree(TreeNode* root) {
        int count=0;
       bool ans= checkUnival(root,count);
       // cout<<count;  This gives number of subtrees that are unival.
        return ans;
    }
};