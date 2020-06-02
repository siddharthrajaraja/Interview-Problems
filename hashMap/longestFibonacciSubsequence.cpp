#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 100000
#define REP(i,a,b) for(ll i=a;i<b;i++)
int fib[MAX]={0};

void formFib(){
    ll i;
    int a=0;
    int b=1;
    fib[0]=1;
    fib[1]=1;
    
    while(b<=1000){
        int sum=a+b;
        fib[sum]=1;
        a=b;
        b=sum;
    }
    
}

int main(){
    formFib();
    ll t;cin>>t;
    
    while(t--){
        ll n;cin>>n;
        while(n--){
        ll ele;cin>>ele;
        if(fib[ele]==1)cout<<ele<<" ";
        
        }
        cout<<endl;
        
    }
    
    
    
    return 0;
}