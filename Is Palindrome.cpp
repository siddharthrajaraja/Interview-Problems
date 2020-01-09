//head is the head of you linked list
// Following is the node structure
/**************
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
***************/
#define MAX 1000000
typedef struct stack{
    int data[MAX];
    int tos;
}stack;


bool check_palindrome(node* head)
{	
stack x;
x.tos=-1;
    node *p;
 	p=head;
 	while(p!=NULL){
        if(x.tos==-1){
            x.data[++x.tos]=p->data;
            
        }
        else{
            if(x.data[x.tos]==p->data)
            	x.tos--;
            else x.data[++x.tos]=p->data;
            
        }
        p=p->next;
    }
 	if(x.tos==-1)return true;
 	return false;
    //write your code here
}
