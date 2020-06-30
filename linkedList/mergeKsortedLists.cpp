/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
    priority_queue<int,vector<int>,greater<int>>Q;    
    for(auto ele:lists){
        ListNode *q=ele;
        while(q!=NULL){
            //cout<<q->val<<" ";    
            Q.push(q->val);
            q=q->next;
                
        }
    }
        ListNode *soltn=NULL;
        ListNode *tail=NULL;
        while(!Q.empty()){
            ListNode *newNode=new ListNode();
            newNode->val=Q.top();
            newNode->next=NULL;
            if(soltn==NULL){
                soltn=newNode;
                tail=newNode;
            
            }
            else{
                tail->next=newNode;
                tail=tail->next;
            }
            //cout<<Q.top()<<" ";
            Q.pop();
        }
        
        return soltn;
    }
};