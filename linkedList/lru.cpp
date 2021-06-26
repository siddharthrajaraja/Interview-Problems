#include<bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    
    typedef struct node{
        struct node *next;
        struct node *prev;
        int val;
        int key;
    }node;

    node *createNode(int key,int val){
        node *newNode=new node;
        newNode->next=NULL;
        newNode->prev;
        newNode->val=val;
        newNode->key=key;
        return newNode;
    }

    node *head;
    node *tail;
    unordered_map<int,node*>nodeLookup;
    unordered_map<int,bool>nodeExistLookup;
    int SIZE;
    int curSize;

    void insertEnd(int key,int val){
        
        nodeExistLookup[key]=true;
        node *newNode=createNode(key,val);
        nodeLookup[key]=newNode;

        if(head==NULL){
            head=newNode;
            tail=newNode;
            return ;
        }

        tail->next=newNode;
        newNode->prev=tail;
        tail=tail->next;

    }
    
    
    void printList(){
        
        node *p=head;
        cout<<"List : ";
        while(p!=NULL){
            cout<<p->val<<" ";
            p=p->next;
        }
        cout<<endl;
        
    }
    
    
    void appendEnd(node *currentNode){
        
        if(head==NULL){
            head=currentNode;
            tail=currentNode;
            return;
        }

        tail->next=currentNode;
        currentNode->prev=tail;
        tail=tail->next;

    }

    void deleteNode(node *currentNode){
        

        if(currentNode==head){
            
            if(currentNode->next==NULL){
                head=NULL;
                tail=NULL;
                return ;
            }
            head=head->next;
            currentNode->next=NULL;
            return ;
        }
        
        if(currentNode==tail){
            tail=currentNode->prev;
            currentNode->prev=NULL;
            return ;
        }

        node *prevNode=currentNode->prev;
        prevNode->next=currentNode->next;
        currentNode->next->prev=prevNode;
        currentNode->next=NULL;
        currentNode->prev=NULL;


    }

    LRUCache(int capacity) {
        SIZE=capacity;
        head=NULL;
        tail=NULL;
        curSize=0;    
    }
    
    int get(int key) {

        if(nodeExistLookup[key]){

            node *currentNode=nodeLookup[key];
            deleteNode(currentNode);
            appendEnd(currentNode);
            //printList();
            return currentNode->val;

        }
        return -1;
        
    }
    
    void put(int key, int value) {
        if(nodeExistLookup[key]){// update value and delete the node and append it to end
            node *currentNode=nodeLookup[key];
            currentNode->val=value;
            deleteNode(currentNode);
            appendEnd(currentNode);
        }
        else{// add node to the end of the list
            insertEnd(key,value);
            curSize++;
        }

        if(curSize>SIZE){// remove front from ll
            
            nodeExistLookup[head->key]=false;
            deleteNode(head);
            curSize--;
        }
        //puts("Put :");
        //cout<<curSize<<" "<<SIZE<<endl;
        //printList();

    }
};
