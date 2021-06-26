#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a;i<b;i++)
#define vi vector<int>
#define vvi vector<vi>

class Solution {
public:

    const int MAX=1e3;

    typedef struct node{
        
        struct node *next;
        int val;

    }node;

    unordered_map<int,node*>nodeDic;
    unordered_map<int,bool>parentDic;


    void createNode(int val){
        node *newNode=new node;
        newNode->next=NULL;
        newNode->val=val;
        nodeDic[val]=newNode;
        parentDic[val]=true;
    }


    node *parent(node *p){
        node *q=p;
        while (p->next!=NULL)
        {

            p=p->next;
            /* code */
        }
        
        while (q->next!=NULL&&q!=p)
        {
            node *t=q->next;
            q->next=p;
            q=t;

            /* code */
        }
        
        return p;


    }

    vi ans;

    void merge(int a,int b){
        node *nodeA=nodeDic[a];
        node *nodeB=nodeDic[b];
        node *parentA=parent(nodeA);
        node *parentB=parent(nodeB);
        
        if(parent(nodeA)!=parent(nodeB)){
            
            
            parentA->next=parentB;
            parentDic[a]=false;
            parentDic[b]=true;
        }
        else{
            ans={a,b};
        }

    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int i;
        REP(i,1,MAX+1){
            createNode(i);
        }

        for(auto ele:edges){
            int s=ele[0];
            int d=ele[1];
            merge(s,d);
        }

        return ans;
    }
};