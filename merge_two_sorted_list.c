/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include<malloc.h>


struct ListNode * insertEnd(struct ListNode *head,int ele){
    struct ListNode *p=(struct ListNode *)malloc(sizeof(struct ListNode));
    p->val=ele;
    p->next=NULL;
    
    if(head==NULL){
        head =p;
        return head;
    }
    struct ListNode *q=head;
    while(q->next!=NULL)q=q->next;
    q->next=p;
    return head;
    
}


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode * start=NULL;
    
    while(l1!=NULL && l2!=NULL){
        if(l1->val<=l2->val){
            start=insertEnd(start,l1->val);
            l1=l1->next;
            
        }   
        else{
            start=insertEnd(start,l2->val);
            l2=l2->next;
        }
        
    }
    
    while(l1!=NULL){
        start=insertEnd(start,l1->val);
        l1=l1->next;
    }
    
    while(l2!=NULL){
        start=insertEnd(start,l2->val);
        l2=l2->next;
    }
    
    return start;

}

