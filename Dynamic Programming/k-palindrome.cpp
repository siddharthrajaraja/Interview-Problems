#include <bits/stdc++.h>
using namespace std;


bool is_k_palin(string s,int k);

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		string s ;
		cin>>s;
		int k;
		cin>>k;
		
		cout<<is_k_palin(s,k)<<endl;
	}
	return 0;
}// } Driver Code Ends

#define REP(i,a,b) for(int i=a;i<b;i++)
#define REPI(i,a,b) for(int i=a;i>=b;i--)

/*You are required to complete this function*/
bool is_k_palin(string s,int k)
{   int size=s.size();
    string reverse;
    vector<vector<int>>table;
    vector<int>perRow(size+1,0);
    
    int i;
    
    REPI(i,size-1,0)reverse+=s[i];
    
    REP(i,0,size+1)table.push_back(perRow);
    
    REP(i,1,size+1){
        int j;
        REP(j,1,size+1){
            if(s[i-1]==reverse[j-1]){
                table[i][j]=table[i-1][j-1]+1;
                
            }
            else{
                table[i][j]=max(table[i-1][j],table[i][j-1]);
            }
        }
    }
    
    
    if(size-table[size][size]<=k)return true;
    return false;
    
    
    
    
//Your code here
}