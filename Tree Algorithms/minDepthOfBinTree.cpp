#define pushb push_back
#define popf pop_front
#define popb pop_back
#define pushf push_front
#define mp make_pair

class Solution {
public:
    
    int BFS(TreeNode *root,int mini){
        deque<pair<TreeNode *,int>>Q;
        Q.pushb(mp(root,1));
        
        while(!Q.empty()){
            int depth=Q.front().second;
            TreeNode * front=Q.front().first;
            Q.popf();
            if(front->left!=NULL){
                Q.pushb(mp(front->left,depth+1));
            }
            if(front->right!=NULL){
                Q.pushb(mp(front->right,depth+1));
            }
            if(front->left==front->right && front->left==NULL){
                if(mini>=depth)mini=depth;
            }
            
        }
        return mini;
    }
    
    int minDepth(TreeNode* root) {
        if(root==NULL)return 0;
        int mini=INT_MAX;
        
        return BFS(root,mini);
    }
};