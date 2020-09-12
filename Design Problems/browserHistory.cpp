#include<bits/stdc++.h>

using namespace std;

#define instruct cout<<"ENTER CHOICES (INTEGERS) : 1)VISIT 2)BACK 3)FORWARD 4)PRINT HISTORY 5)PRINT REVERSE HISTORY 6)EXIT\n";

class BrowserHistory{
	
	typedef struct Node {
		string webpage;
		int index; // 1-Based
		struct Node *next;
		struct Node *prev;
	}Node;
	
	map<int,Node *>dic;

	Node * rear=NULL;
	Node * head=NULL;
	int maxSize=0;

	public:
		
		void printHistory(){
			Node * p=head;

			while(p!=NULL){
				cout<<"("<<p->index<<")"<<p->webpage<<" ";
			   	p=p->next;
				
			}
			cout<<endl;
		
		}

		void printReverseHistory(){
			Node *p=rear;

			while(p!=NULL){
				
				cout<<"("<<p->index<<")"<<p->webpage<<" ";
				p=p->prev;

			}
			cout<<"\n";

		}
			
		BrowserHistory(string homepage) {
    if(rear==NULL && head==NULL){
			//		Node *node=(Node *)malloc(sizeof(Node));
					Node * node =new Node;
            
					node->webpage=homepage;
					node->prev=NULL;
					node->next=NULL;
					node->index=1;
					rear=node;
					head=node;
					dic[1]=node;
					maxSize++;
			}
			//printHistory();

    
    }
    
    void visit(string url) {
        
        	//Node *node=(Node *)malloc(sizeof(Node));
			Node * node =new Node;
            
			rear->next=node;
			node->webpage=url;
			node->next=NULL;
			node->prev=rear;
			node->index=rear->index+1;
			rear=node;
			dic[node->index]=node;
			
			if(node->index<maxSize)maxSize=node->index;
			else 
				maxSize=node->index;

			//printHistory();

        
    }
    
    string back(int steps) {
        if(rear==NULL){
				return "";
			}
			if(rear->index-steps<=0){
				rear=dic[1];
				return rear->webpage;
			}
			int moveTo=rear->index-steps;
            
			rear=dic[moveTo];
			
			return rear->webpage;
		        
        }
    
    string forward(int steps) {
        
        if(rear==NULL){
				return "";
			}
			//cout<<"MAX SIZE IS :"<<maxSize<<"\n"; 
			if(maxSize<steps+rear->index){
				rear=dic[maxSize];
				return rear->webpage;
			}

			int moveTo=rear->index+steps;
			rear=dic[moveTo];
			return rear->webpage;

    }	



};

int main(){
	string homepage,website;
	int steps;

	cout<<"ENTER HOMEPAGE :";cin>>homepage;
	BrowserHistory *obj=new BrowserHistory(homepage);
	while(1){
		instruct
		int instruction;
		cin>>instruction;
		
		if(instruction==6) break;

		switch(instruction){
			case(1):
					cout<<"ENTER WEBSITE TO VISIT: ";
				
					cin>>website ;
					obj->visit(website);
					break;
			case(2) :
					cout<<"ENTER NUMBER OF STEPS TO GO BACK: ";
					cin>>steps;
					cout<<"Rear shifted to :"<<obj->back(steps)<<"\n";
					break;
			case(3): 
				   	cout<<"ENTER NUMBER OF STEPS TO GO FORWARD: ";
					cin>>steps;
					cout<<"Rear shifted to :"<<obj->forward(steps)<<"\n";
					break;
			case(4):
					obj->printHistory();
					break;
			case(5):
					obj->printReverseHistory();
					break;

			default: 
					cout<<"INVALID CHOICE ";

		}


	
	}	

	return 0;
}