class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi=INT_MIN;
        int i=0;
        int j=height.size()-1;
        while(i<j){
            int area=(j-i)*min(height[i],height[j]);
            
            if(maxi<=area)maxi=area;
            
            if(height[i]>height[j]){
                j--;
            }
            else if(height[j]>height[i]){
                i++;
            }
            else{
                
                if(height[j-1]<height[i])i++;
                else j--;
            }
        }
        
        if(maxi==INT_MIN)return 0;
        return maxi;
    }
};