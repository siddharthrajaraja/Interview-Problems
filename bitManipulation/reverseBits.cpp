class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<int>Q;
        int times=0;
        while(times!=32){
            if((n&(1<<times))!=0){
                Q.push_back(1);
                //cout<<(1<<times)<<" ";
            }
            else{
                Q.push_back(0);
            }
            times++;
        }
        
        uint32_t ele=0;
        reverse(Q.begin(),Q.end());
        
        int i=0;
        while(i!=32){
            //cout<<" element : "<<Q[i]<<" ";
            ele+=Q[i]*(1<<i);
            i++;
        }
        
        return ele;
        
    }
};