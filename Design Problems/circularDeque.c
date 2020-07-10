#define MAX 1000


typedef struct {
    int arr[MAX];
    int front;
    int rear;
    int size;
    int count;
    
} MyCircularDeque;

/** Initialize your data structure here. Set the size of the deque to be k. */

MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque * p=(MyCircularDeque *)malloc(sizeof(MyCircularDeque));
    p->size=k;
    p->front=0;
    p->count=0;
    p->rear=-1;
    return p;
}

/** Adds an item at the front of Deque. Return true if the operation is successful. */

/** Adds an item at the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertLast(MyCircularDeque* p, int value) {
  
    if(p->size==p->count)return false;
    p->count++;
    if(p->count==0){
        p->rear=(p->rear+1)%p->size;
        p->arr[p->rear]=value;
        return true;
    }
    p->rear=(p->rear+1)%(p->size);
    p->arr[p->rear]=value;
    return true;
}

bool myCircularDequeInsertFront(MyCircularDeque* p, int value) {
  if(p->count==p->size)return false;
    if(p->count==0){
        if(myCircularDequeInsertLast(p,value))return true;   
    }
    p->count++;
   
    p->front=(p->front-1)%(p->size);
    if(p->front<0)p->front=p->size+p->front;
    p->arr[p->front]=value;
    return true;
    
}

/** Deletes an item from the front of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteFront(MyCircularDeque* p) {
    
    if(p->count==0)return false;
    
    p->count--;
    p->front=(p->front+1)%(p->size);
    return true;
}

/** Deletes an item from the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteLast(MyCircularDeque* p) {
    
    if(p->count==0)return false;
    p->count--;
    p->rear=(p->rear-1)%p->size;
    if(p->rear<0)p->rear=(p->size+p->rear);
    return true;
  
}

/** Get the front item from the deque. */
int myCircularDequeGetFront(MyCircularDeque* p) {
    if(p->count==0)return -1;
    return p->arr[p->front];
    
}

/** Get the last item from the deque. */
int myCircularDequeGetRear(MyCircularDeque* p) {
    if(p->count==0)return -1;
    return p->arr[p->rear];
}

/** Checks whether the circular deque is empty or not. */
bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
  if(obj->count==0)return true;
    return false;
}

/** Checks whether the circular deque is full or not. */
bool myCircularDequeIsFull(MyCircularDeque* p) {
  if(p->count==p->size)return true;
    return false;
}

void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj);
}

/**
 * Your MyCircularDeque struct will be instantiated and called as such:
 * MyCircularDeque* obj = myCircularDequeCreate(k);
 * bool param_1 = myCircularDequeInsertFront(obj, value);
 
 * bool param_2 = myCircularDequeInsertLast(obj, value);
 
 * bool param_3 = myCircularDequeDeleteFront(obj);
 
 * bool param_4 = myCircularDequeDeleteLast(obj);
 
 * int param_5 = myCircularDequeGetFront(obj);
 
 * int param_6 = myCircularDequeGetRear(obj);
 
 * bool param_7 = myCircularDequeIsEmpty(obj);
 
 * bool param_8 = myCircularDequeIsFull(obj);
 
 * myCircularDequeFree(obj);
*/