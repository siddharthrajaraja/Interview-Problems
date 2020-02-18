/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head){
    struct ListNode *preptr,*ptr,*postptr,*tmp1,*tmp2,*tmp3,*temp;
    int cnt;
    if (head==NULL || head->next==NULL || head->next->next==NULL)
    {
        return head;
    }
    preptr=head;
    ptr=head->next;
    postptr=ptr->next;
    while(postptr!=NULL)
    {
        tmp1=postptr->next;
        tmp2=ptr->next;
        tmp3=preptr->next;
        preptr->next=tmp2;
        postptr->next=tmp3;
        ptr->next=tmp1;
        postptr=ptr;
        cnt=0;
        preptr=preptr->next;
        while(postptr!=NULL && cnt<2)
        {
            ptr=postptr;
            postptr=postptr->next;
            cnt++;
        }
    }
    // temp=head;
    // while(temp!=NULL)
    // {
    //     printf("%d ",temp->val);
    //     temp=temp->next;
    // }
    return head;
}

