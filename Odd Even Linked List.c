/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include<malloc.h>

struct ListNode* insertEnd(struct ListNode *head,int ele){
   struct  ListNode *p;
    p=head;
   struct ListNode *node=(struct ListNode *)malloc(sizeof(struct ListNode));
    node->val=ele;
   // printf("Value: %d ",node->val);
    node->next=NULL;
    if(p==NULL){
        head=node;
        
        return head;
    }
    while(p->next!=NULL)p=p->next;
    p->next=node;
    
    return head;
    
}

void printList(struct ListNode *head){
    struct ListNode*p=head;
    while(p!=NULL){
        printf("%d ",p->val);
        p=p->next;
    }
    printf("\n");
    
}

struct ListNode* oddEvenList(struct ListNode* head){
    if(head==NULL)return NULL;
    
   struct ListNode *p;
    p=head;
    int c=0;
   struct  ListNode *even=NULL;
  struct  ListNode *odd=NULL;
    
    
    while(p!=NULL){
        if(c%2==0) even= insertEnd(even,p->val);
        else odd=insertEnd(odd,p->val);
        c++;
       // printf("%lld %lld\n",even,odd);
        p=p->next;
    }
    
      printList(even);
      printList(odd);
      
    
   struct ListNode *evenstart=even;
    while(evenstart->next!=NULL)evenstart=evenstart->next;
    evenstart->next=odd;
    evenstart=even;
    
    printList(evenstart);
    
    return evenstart;
}

