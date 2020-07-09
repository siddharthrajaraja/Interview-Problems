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
    
    ListNode *satisfies(ListNode *head,int k){
        int count=1;
        ListNode *p=head;
        
        while(p!=NULL && count!=k){
            p=p->next;count++;
        }
        if(count==k)return p;
        return NULL;
        
    }
    
    ListNode *reverseList(ListNode *start,ListNode *end){
        ListNode *pre=NULL;
        ListNode *p=start;
        while(p!=end){
            ListNode *t=p->next;
            p->next=pre;
            pre=p;
            p=t;
        }
        p->next=pre;
        return p;
    }
    
    
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL)return NULL;
        if(k==1)return head;
        ListNode *p=head;int i=0;
        ListNode *pre=NULL;
        
        
        while(1){
            
            ListNode *endKth=satisfies(p,k);
            
            if(endKth==NULL){
                    if(pre==NULL)return head;
                    pre->next=p;
                    return head;
            }
            else{
                
                ListNode *t=endKth->next;
                ListNode *newHead=reverseList(p,endKth);
                
                if(i==0){
                    
                    head=newHead;
                    i++;
                    pre=p;
                    p=t;
                    
                }
                else{
                    
                    if(newHead!=p){
                        pre->next=newHead;
                        pre=p;
                        p=t;
                        i++;
                        
                    }
                    else{
                        
                        pre->next=p;
                        return head;
                    }
                }
            }
        }
        return head;
    }
};