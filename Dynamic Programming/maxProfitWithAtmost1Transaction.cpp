typedef long long ll;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        priority_queue<ll,vector<ll>,greater<ll>>arr;
        ll present=-1;
        ll profit=0;
    
        for(auto ele:prices){
            present=ele;
        if(arr.empty()){
            arr.push(ele);profit=0;
        }
        else{
            //cout<<"Topmost ele: "<<arr.top()<<" \n";
            if(profit<(present-(arr.top()))){
                profit=(present-(arr.top()));
            }
            arr.push(ele);

        }
            
        }
        
        return profit;   
    }
};