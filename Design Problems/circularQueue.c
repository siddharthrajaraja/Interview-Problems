#define MAX 1000
#define pri(ele) printf("%d\n",ele);
//#define REP(i,a,b,size) for(int i=a;i!=b;i=(i+1)%size)

typedef struct {
    int arr[MAX];
    int front;
    int rear;
    int count;
    int size;
    
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue * p=(MyCircularQueue *)malloc(sizeof(MyCircularQueue));
    p->size=k;
    p->count=0;
    p->front=0;
    p->rear=-1;
    return p;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* p, int value) {
    if(p->count==p->size)return false;
    p->count++;
    if(p->rear==-1){
        p->rear++;
        p->arr[p->rear]=value;
        pri(p->arr[p->rear]);
        //cout<<p->arr[p->rear]<<"\n";
        return true;
    }
    p->rear=(p->rear+1)%p->size;
    p->arr[p->rear]=value;
     pri(p->arr[p->rear]);
    return true;
    
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* p) {
     if(p->count==0)return false;
    p->count--;
    p->front=(p->front+1)%p->size;
    return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* p) {
   if(p->count==0)return -1;
    return p->arr[p->front];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* p) {
    /*int i;
    
    REP(i,p->front,p->rear+1,p->size){
        pri(p->arr[i]);
    }*/
    
    if(p->count==0)return -1;
    return p->arr[p->rear];
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* p) {
  if(p->count==0)return true;
    return false;
    
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* p) {
  if(p->count==p->size)return true;
    return false;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/