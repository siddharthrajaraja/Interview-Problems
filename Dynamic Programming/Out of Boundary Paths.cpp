#define REP(i,a,b) for(int i=a;i<b;i++)
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>


class Solution {
public:
    int MOD = 1e9 + 7;
    int dp[52][52][52]={-1};
    
    bool isValid(int r,int c,int x,int y){
        if(x>=0&&x<r){
            if(y>=0&&y<c)
                return true;
        }
        return false;
    }
    
    int dfs(int r,int c,int x,int y,int moves){
        
        if(!isValid(r,c,x,y)){
            return 1;
        }
        
        if(moves==0){
            //dp[moves][x][y]=0;
            return 0;
        }
        
        if(dp[moves][x][y]!=-1){
            return dp[moves][x][y]%MOD;
        }
        
        
        //cout<<"here";
        int left=dfs(r,c,x,y-1,moves-1)%MOD;
        int right=dfs(r,c,x,y+1,moves-1)%MOD;
        int top=dfs(r,c,x-1,y,moves-1)%MOD;
        int down=dfs(r,c,x+1,y,moves-1)%MOD;
        
        int ans=((left+right)%MOD+(top+down)%MOD)%MOD;
        
        dp[moves][x][y]=ans%MOD;
        return dp[moves][x][y]%MOD;
        
        
    }
    
    int findPaths(int m, int n, int N, int i, int j) {
        
        int I;
        REP(I,0,52){
            int J;
            REP(J,0,52){
                int K;
                REP(K,0,52){
                    dp[I][J][K]=-1;
                }
            }
            
        }
        
        int ans=dfs(m,n,i,j,N)%MOD;
        return ans;
        
    }
};