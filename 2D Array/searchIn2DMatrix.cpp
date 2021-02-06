class Solution {
public:
    
    bool isValid(int R,int C,int x,int y){
        return x>=0&&x<R&&y>=0&&y<C;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int R=matrix.size();
        int C=matrix[0].size();
        
        int x=0;
        int y=C-1;
        
        while(1){
            
            if(!isValid(R,C,x,y)){
                return false;
            }
            
            if(matrix[x][y]==target){
                break;
            }
            
            if(target<matrix[x][y]){
                y--;
            }
            else{
                x++;
            }
            
        }
        
        return true;
        
    }
};