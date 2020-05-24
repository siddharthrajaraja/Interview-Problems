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

class Solution {
public:
    
    void bfs(TreeNode *root,deque<vector<int>>&ans){
        deque<vector<TreeNode *>>arr;
        arr.pushb({root});
        ans.pushb({root->val});
        
        while(!arr.empty()){
            vector<TreeNode *>child=arr.front();
            arr.popf();
            vector<TreeNode *>insertChild;
            vector<int>childAns;
            for(auto ele:child){
                if(ele->left!=NULL){
                    insertChild.pushb(ele->left);
                    childAns.pushb(ele->left->val);
                }
                if(ele->right!=NULL){
                    insertChild.pushb(ele->right);
                    childAns.pushb(ele->right->val);
                }
                
            }
            if(!insertChild.empty())
            {   arr.pushb(insertChild);
                ans.pushb(childAns);
            }
            
        }
        
        
    }
    
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL)return {};
        deque<vector<int>>ans;
        bfs(root,ans);
        vector<int>soltn;
        for(auto each:ans){
            soltn.pushb(*each.rbegin());
            /*for(auto every:each){
                cout<<every<<" ";
            }*/
          //  cout<<endl;
        }
            return soltn;
        
    }
};