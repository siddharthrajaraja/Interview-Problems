typedef long long ll;

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<ll>maxHeap;
    priority_queue<ll,vector<ll>,greater<ll>>minHeap;
    ll sizeMinHeap=0;
    ll sizeMaxHeap=0;
    
    MedianFinder() {
        maxHeap={};
        minHeap={};
        sizeMinHeap=0;
        sizeMaxHeap=0;
    }
    
    void balance(){
        ll t;
        if(sizeMaxHeap+2==sizeMinHeap){
            t=minHeap.top();
            minHeap.pop();
            maxHeap.push(t);
            sizeMaxHeap++;
            sizeMinHeap--;
        }
        else if(sizeMinHeap+2==sizeMaxHeap){
            t=maxHeap.top();
            maxHeap.pop();
            minHeap.push(t);
            sizeMaxHeap--;
            sizeMinHeap++;
        }
    }
    
    void addNum(int num) {
        if(sizeMaxHeap==0){
                maxHeap.push(num);
                sizeMaxHeap++;
        }
        else{
            if(maxHeap.top()>=num){maxHeap.push(num);sizeMaxHeap++;}
            else {minHeap.push(num);sizeMinHeap++; }
        }
        balance();
        
    }
    
    double findMedian() {
        if(sizeMaxHeap==sizeMinHeap)return (double) (maxHeap.top()+minHeap.top())/2;
        if(sizeMaxHeap>sizeMinHeap)return (double) maxHeap.top();
        return (double) minHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */