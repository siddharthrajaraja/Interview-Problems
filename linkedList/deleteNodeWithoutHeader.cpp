
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}*head;
*/
void deleteNode(Node *node)
{   
    Node *p=node,*q;
    while(p->next!=NULL ){
        q=p;
        p->data=p->next->data;
        p=p->next;
    }
    
    q->next=NULL;
    
   // Your code here
}
