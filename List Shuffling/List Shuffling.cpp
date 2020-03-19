#include<iostream>
#include<malloc.h>

using namespace std;

typedef struct node{
    long long int val;
    struct node *next;
}node;

typedef struct head{
    node *start;
    node *tail;
}head;

void createList(head *,long long int); // This function is to create Linked List initially in O(1).
void printList(head *);  // This function is to print List in O(n).
node * findMiddle(head *); // This returns the pointer to node which lies exactly in Middle . O(n/2) => O(n).
node * shuffle(head * ,head *); // This is Shuffling which returns new header of Linked List in O(n).


int main(){
    std::cout<<"Enter number of Elements in Linked List : ";
    int n; std::cin>>n;
    head x;
    x.start=NULL;
    x.tail=NULL;

    while(n!=0){
        std::cout<<"\nEnter data : "; long long int ele;std::cin>>ele;
        createList(&x,ele);
        std::cout<<endl;
        printList(&x);
        n--;
    }

    node * middle=findMiddle(&x);

    head h1; h1.start=middle->next;
    middle->next=NULL;
    head h2; h2.start=x.start;

    std::cout<<"\nFirst List obtained :"<<endl ;printList(&h1);
    std::cout<<"\nSecond List obtained :"<<endl ;printList(&h2);
    
    x.start=shuffle(&h1,&h2);

    std::cout<<"\nAfter Shuffling:"<<endl ;printList(&x);
    

    return 0;
}

void createList(head *t,long long int ele){
    node * newNode=(node *)malloc(sizeof(node));
    newNode->next=NULL;
    newNode->val=ele;
    if(t->start==NULL){
            t->start=newNode;
            t->tail=newNode;
            return ;
    }
    t->tail->next=newNode;
    t->tail=newNode;
}

void printList(head *t){
    node *p;
    p=t->start;
    if(t->start==NULL){
        std::cout<<"List Empty"<<endl;
        return ;
    }
    std::cout<<"\nList Obtained : ";
    while(p!=NULL){
        std::cout<<p->val<<"\t";
        p=p->next;
    }

}

node * findMiddle(head *t){
    node *slow=t->start;
    node *fast=t->start;

    while(fast->next!=NULL && fast->next->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    std::cout<<"\nMiddle element: "<<slow->val<<endl;
    return slow;
}

node * shuffle(head *t1,head *t2){
    node *p=t1->start;
    node *q=t2->start;

    node * temp1=p->next;
    node * temp2=q->next;

    while(temp1!=NULL){
        p->next=q;
        q->next=temp1;
        p=temp1;
        temp1=temp1->next;
        q=temp2;
        temp2=temp2->next;

    }

    p->next=q;

    return t1->start;


}