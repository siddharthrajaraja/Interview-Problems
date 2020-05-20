#include<bits/stdc++.h>
using namespace std;
#define MAX 1001
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


void getShortestCommonSupersequence(string,string,string);


string getLCS(string x,string y){
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

    return soltn;
    //cout<<"LCS is : "<<soltn<<" ";


}

string fillTable(string x,string y){
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

   // printTable(x,y);

   string LCS= getLCS(x,y);
   return LCS;
}



int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    string a,b;
    cin>>a>>b;
    fflush(stdin);
    fflush(stdout);
    
   string lcs=fillTable(a,b);

    //cin>>a>>b>>lcs;
    getShortestCommonSupersequence(a,b,lcs);
    return 0;
}

void getShortestCommonSupersequence(string a,string b,string lcs){
    int i=0,j=0,l=0;
    int lcsSize=lcs.size();
    string ans="";

    while(l<lcsSize){
        // if both all the characters are same as that of LCS.
        if(a[i]==lcs[l] && b[j]==lcs[l]){
                ans+=lcs[l];l++;i++;j++;
        }
        else{
            // only one of them same .
            if(a[i]==lcs[l]){
                ans+=b[j];j++;
            }
            else if(b[j]==lcs[l]){
                ans+=a[i];i++;
            }
            // none of them same !!
            else{
                    ans+=a[i];
                    ans+=b[j];
                    j++;
                    i++;
            }

        }
    }

    while(i!=a.size()){
        ans+=a[i];
        i++;
    }

    while(j!=b.size()){
        ans+=b[j];
        j++;
    }

        cout<<ans;
    

}