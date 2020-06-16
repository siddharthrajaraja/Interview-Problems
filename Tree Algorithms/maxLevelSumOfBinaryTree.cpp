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
#define pushb push_back
#define popb pop_back
#define popf pop_front
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if(root==NULL){return 0;}
        deque<deque<TreeNode*>>Q;
        Q.pushb({root});
        int index=0;
        int maxii=INT_MIN;
        int level=0;
        int pos=-1;
        while(!Q.empty()){
            deque<TreeNode*>frontQ=Q.front();
            deque<TreeNode*>child;
            Q.popf();
            int sum=0;
            while(!frontQ.empty()){
                TreeNode * fr=frontQ.front();
                sum+=fr->val;
                frontQ.popf();
                if(fr->left!=NULL){
                    child.pushb(fr->left);
                }
                if(fr->right!=NULL){
                    child.pushb(fr->right);
                }
            }
            if(!child.empty()){
                Q.pushb(child);
            }
            //cout<<sum<<"\n";
            if(maxii<sum){
                maxii=sum;
                pos=level;
            }
            level++;
            
        }
        return pos+1;
        
    }
};