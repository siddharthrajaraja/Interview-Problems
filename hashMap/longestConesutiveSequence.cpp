#define REP(i,a,b) for(int i=a;i<b;i++)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        set<int>setArr;
        for(auto ele:nums){
            setArr.insert(ele);
        }
        vector<int>arr;
        for(auto ele:setArr){
            arr.push_back(ele);
        }
        
        int count =1;
        int i;
        int maxi=INT_MIN;
        REP(i,1,arr.size()){
            cout<<arr[i-1]+1<<" "<<arr[i];
            if(arr[i-1]+1==arr[i])count++;
            else{
                count=1;
            }
                   if(maxi<=count)maxi=count;
         
        }
        if(maxi==INT_MIN)return 1;
        return maxi;
        
    }
};