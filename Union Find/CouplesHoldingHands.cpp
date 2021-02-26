#include<bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
#define vi vector<int>
#define mii map<int,int>
#define umii unordered_map<int,int>
#define dqi deque<int>
#define pqL priority_queue<int,vector<int>,less<int>>
#define pqG priority_queue<int,vector<int>,greater<int>>
#define REP(i,a,b) for(int i=a;i<b;i++)

class Solution {
public:
    typedef struct node
    {
        struct node *next;
        int val;

    }node;

    unordered_map<int,node *>dic;

    void init(int i){
        node *newNode= new node;
        newNode->next=NULL;
        newNode->val=i;
        dic[i]=newNode;
    }

    int minSwapsCouples(vector<int>& row) {
        int maxi=*max_element(row.begin(),row.end());
        int i;
        REP(i,0,maxi+1){
            //cout<<"val :"<<i<<endl;
            init(i);
        }

        i=0;

        while(i<row.size()-1){
            node *nodeA=dic[row[i]];
            node *nodeB=dic[row[i+1]];
            nodeA->next=nodeB;
            nodeB->next=nodeA;
            i++;
            i++;
        }

        i=0;
        int count=0;
        while(i<=maxi){
            node *nodeA=dic[i];
            node *nodeB=nodeA->next;
            if(nodeA->val+1!=nodeB->val){
                node *nodeC=dic[i+1];
                node *nodeD=nodeC->next;
                nodeA->next=nodeC;
                nodeB->next=nodeD;
                nodeD->next=nodeB;
                count++;
            }
            i++;
            i++;
        }
        return count;

    }
};

int main(){
    fastIO
    vector<int>row;
    int n;
    cin>>n;
    int i;
    REP(i,0,n){
        int ee;
        cin>>ee;
        row.push_back(ee);
    }


    Solution *obj=new Solution;
    cout<<"Answer :"<<obj->minSwapsCouples(row);      
    return 0;
}