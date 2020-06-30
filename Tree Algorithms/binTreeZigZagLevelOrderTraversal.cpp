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
#define popf pop_front
#define vi vector<int>
#define di deque<int>
#define dvi deque<vector<int>>
#define vvi vector<vector<int>>
#define REP(i,a,b) for(int i=a;i<b;i=i+2)

class Solution {
public:
    
    vvi bfs(TreeNode *root){
        deque<deque<TreeNode *>> Q;
        Q.pushb({root});
        
        vvi soltn={{root->val}};
        
        while(!Q.empty()){
            deque<TreeNode *>front=Q.front();
            deque<TreeNode *>child;
            Q.popf();
            while(!front.empty()){
                TreeNode *each=front.front();
                front.popf();
                
                if(each->left!=NULL){
                    child.pushb(each->left);
                }
                if(each->right!=NULL){
                    child.pushb(each->right);
                }
                
            }
            
            if(!child.empty()){
                Q.pushb(child);
                vi insertChild;
                for(auto ele:child){
                    insertChild.pushb(ele->val);
                }        
                soltn.pushb(insertChild);
            }
            
        }
        
       return soltn; 
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        vvi soltn=bfs(root);
        
        int i;
        REP(i,1,soltn.size()){
            int j=0;
            int k=soltn[i].size()-1;
            while(j<k){
                int temp=soltn[i][j];
                soltn[i][j]=soltn[i][k];
                soltn[i][k]=temp;
                j++;k--;
            }
        }
        
        
        return soltn;
        
    }
};