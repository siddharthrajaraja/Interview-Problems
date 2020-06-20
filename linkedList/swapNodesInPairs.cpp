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
    
    
    ListNode* swapPairs(ListNode* head) {
        
        if(head==NULL)return NULL;
        if(head->next==NULL)return head;
        
        ListNode *i;ListNode *j;ListNode *preI;ListNode *t;
        
        i=head;
        j=head->next;
        head=j;
        
        while(i->next!=NULL){
            
            t=j->next;
            j->next=i;
            i->next=t;
            preI=i;
            i=i->next;
            
            if(i!=NULL){
                j=i->next;
                preI->next=j;
            }
            else{
                preI->next=i;
                break;
            }
        
        
        }
        // If list has odd number of nodes --
        if(j==NULL){
            preI->next=i;
        }
        return head;
        
        
        
    }
};