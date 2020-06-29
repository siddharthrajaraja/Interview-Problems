 bool comp(string x,string y){
        string ans1=x+y;
        string ans2=y+x;
        if(ans1>ans2)return true;
        return false;
    }
class Solution {
public:
    
   
    
    string largestNumber(vector<int>& nums) {
        
        vector<string>arr;
        int intCount=0;
        for(auto ele:nums){
            if(ele==0)intCount++;
            arr.push_back(to_string(ele));
        }
        if(intCount==nums.size())return "0";
        
        sort(arr.begin(),arr.end(),comp);
        string ans="";
        for(auto ele:arr){
            ans+=ele;
        }
        return ans;
    }
};
