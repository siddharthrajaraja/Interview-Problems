#include<bits/stdc++.h>
#define MAX 1000
using namespace std;
#define REP(i,a,b) for(int i=a;i<b;i++)

void fillTable(vector<vector<int>>&table,int rows ,int cols){

    int i;
    REP(i,0,rows+1){
        int j;
        vector<int>child;
        REP(j,0,cols+1){
            child.push_back(0); 
        }
        table.push_back(child);
    } 

    REP(i,0,rows+1){
        table[i][0]=i;
    }
    REP(j,0,cols+1){
        table[0][j]=j;
    }

  //  cout<<table.size()<<" "<<table[0].size();   
}



int findEditDistance(vector<vector<int>>table,string X,string Y,int rows,int cols){
    //cout<<X<<" "<<Y<<endl;
    int i;

    REP(i,1,rows+1){
        int j;
        REP(j,1,cols+1){
            if(X[i-1]==Y[j-1]){
                table[i][j]=table[i-1][j-1];
            }
            else{
                table[i][j]=min(table[i][j-1], min(table[i-1][j],table[i-1][j-1]))+1;
            }
        } 
    }
    // To debug and print table
    //cout<<endl;
    // REP(i,0,rows+1){
    //     int j;
    //     REP(j,0,cols+1){
    //         cout<<table[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return table[rows][cols];

}

int main(){
    int t;cin>>t;

    while(t--){
        string X,Y;cin>>X>>Y; 
        int x,y;
        x=X.size();
        y=Y.size();
        vector<vector<int>>table;
        fillTable(table,x,y);
        cout<<findEditDistance(table,X,Y,x,y);



    }

    return 0;
}