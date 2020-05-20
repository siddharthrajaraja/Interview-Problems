#include<bits/stdc++.h>
#define MAX 1001
using  namespace std;
#define REP(i,a,b) for(int i=a;i<b;i++)
int table[MAX][MAX]={};

void printTable(string x,string y){
    int i;
    REP(i,0,x.size()+1){
        int j;
        REP(j,0,y.size()+1){
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }

}

void getLCS(string x,string y){
    int i=x.size();
    int j=y.size();
    stack<char>LCS;

    while(i>=1 && j>=1){

        if(x[i-1]==y[j-1]){
            LCS.push(x[i-1]);
            i--;
            j--;
        }
        else{
            if(table[i-1][j]>table[i][j-1]){
                    i--;
            }
            else{
                j--;
            }
        }

    }

    string soltn="";

    while(!LCS.empty()){
        soltn+=LCS.top();
        LCS.pop();
    }

    cout<<"LCS is : "<<soltn<<" ";


}

void fillTable(string x,string y){
    int rows=x.size(),cols=y.size();

    int i=1;

    while(i<=rows){
        int j=1;
        while(j<=cols){
            if(x[i-1]==y[j-1]){
                table[i][j]=table[i-1][j-1]+1;
            }
            else{
                table[i][j]=max(table[i-1][j],table[i][j-1]);
            }
            j++;
        }
        i++;
    }

    printTable(x,y);

    getLCS(x,y);
}

int main(){

    string x,y;

    cin>>x>>y;
    fillTable(x,y);



    return 0;
}