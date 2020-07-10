#define MAX 1000000
#define REP(i,a,b) for(int i=a;i<b;i++)

typedef struct {
    int arr[MAX+1];
    
    
} MyHashSet;

/** Initialize your data structure here. */

MyHashSet* myHashSetCreate() {
    MyHashSet * p=(MyHashSet *)malloc(sizeof(MyHashSet));
    int i;
    REP(i,0,MAX+1){
        p->arr[i]=0; // Not Present
    }
    return p;
}

void myHashSetAdd(MyHashSet* p, int key) {
  p->arr[key]=1;
}

void myHashSetRemove(MyHashSet* p, int key) {
  p->arr[key]=0;
}

/** Returns true if this set contains the specified element */
bool myHashSetContains(MyHashSet* obj, int key) {
  if(obj->arr[key])return true;
    return false;
}

void myHashSetFree(MyHashSet* obj) {
    free(obj);
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 
 * myHashSetRemove(obj, key);
 
 * bool param_3 = myHashSetContains(obj, key);
 
 * myHashSetFree(obj);
*/