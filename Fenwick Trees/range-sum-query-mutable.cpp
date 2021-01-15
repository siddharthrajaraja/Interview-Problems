#define MAX 30000+1
#define vi vector<int>
#define REP(i,a,b) for(int i=a;i<b;i++)

class NumArray {
public:
    
    int fenTree[MAX]={0};
    
    
    int fenSize;
    vi arr;
    
    
    void printFenTree(){
        int i;
        cout<<"Fentree is : ";
        REP(i,0,fenSize+1){
            cout<<fenTree[i]<<" ";
        }
        cout<<endl;
        
        cout<<"Arr :";
        
        for(auto ele:arr){
            cout<<ele<<" ";
        }
        cout<<endl;
        
    }
    
    int get2sComplement(int x){
        return x&-x;
    }
    
    
    void initUpdate(int x,int ele){
        
        int fenIndex=x+1;
        
        while(fenIndex<=fenSize){
            
            fenTree[fenIndex]+=ele;
            int twoComplement=get2sComplement(fenIndex);
            int andIndex=fenIndex&twoComplement;
            fenIndex+=andIndex;
        }
        
        
    }
    
    int getSum(int x){
        
        int fenIndex=x+1;
        int sum=0;
        
        while(fenIndex>0){
            sum+=fenTree[fenIndex];
            
            int twoComplement=get2sComplement(fenIndex);
            int andIndex=fenIndex&twoComplement;
            fenIndex-=andIndex;
            
        }
        
        return sum;
        
    }
    
    
    NumArray(vector<int>& nums) {
        int size=nums.size();
        fenSize=size;
        
        int index=0;
        for(auto ele:nums){
            initUpdate(index,ele);
            index++;
        }
        
        arr=nums;
        
    }
    
    void update(int i, int val) {
        
        int initial=arr[i];
        int diff=val-initial;
        arr[i]=val;
        initUpdate(i,diff);
        
    }
    
    int sumRange(int i, int j) {
        int iSum=getSum(i-1);
        int jSum=getSum(j);
        return jSum-iSum;
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */