#define MAX 1000000
#define REP(i,a,b) for(int i=a;i<b;i++)

typedef struct {
    int arr[MAX+1];
} MyHashMap;

/** Initialize your data structure here. */

MyHashMap* myHashMapCreate() {
    MyHashMap * p=(MyHashMap *)malloc(sizeof(MyHashMap));
    int i;
    REP(i,0,MAX+1){
        p->arr[i]=-1;
    }
    return p;
}

/** value will always be non-negative. */
void myHashMapPut(MyHashMap* p, int key, int value) {
  p->arr[key]=value;
}

/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
int myHashMapGet(MyHashMap* obj, int key) {
  return obj->arr[key];  
}

/** Removes the mapping of the specified value key if this map contains a mapping for the key */
void myHashMapRemove(MyHashMap* obj, int key) {
  obj->arr[key]=-1;
    
}

void myHashMapFree(MyHashMap* obj) {
    free(obj);
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);
 
 * int param_2 = myHashMapGet(obj, key);
 
 * myHashMapRemove(obj, key);
 
 * myHashMapFree(obj);
*/