#define REP(i,a,b) for(int i=a;i<b;i++)
class Solution {
public:
    void fillTable(vector<vector<int>>&table,int size){
        int i;
        REP(i,0,size+1){
            vector<int>child;
            int j;
            REP(j,0,size+1){
                child.push_back(0);
            }
            table.push_back(child);
        }
    }
    
    int LCS(vector<vector<int>>&table,string x ,string y,int size){
        int i;
        REP(i,1,size+1){
            int j;
            REP(j,1,size+1){
                if(x[i-1]==y[j-1]){
                    table[i][j]=table[i-1][j-1]+1;
                }
                else{
                    table[i][j]=max(table[i-1][j],table[i][j-1]);
                }
            }
        }
        return table[size][size];
        
    }
    
    int longestPalindromeSubseq(string s) {
        int size=s.size();
        string reversed="";
        int i=size-1;
        while(i>=0){
            reversed+=s[i];
            i--;
        }
        
        
        vector<vector<int>>table;
        fillTable(table,size);
        return LCS(table,s,reversed,size);
        
    }
};