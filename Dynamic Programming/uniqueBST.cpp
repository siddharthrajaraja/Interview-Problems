#include<bits/stdc++.h>
typedef unsigned long long ll;
using namespace std;
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define MAX 101

void getCatlanNumber(vector<ll>&catlans){
    catlans={1,1};
    
    ll i;
    
    REP(i,2,MAX){
        ll j;
        ll sum=0;
        REP(j,1,i+1){
            sum+=catlans[j-1]*catlans[i-j];
            
        }
        catlans.push_back(sum);
    }
    
}

void printCatlans(vector<ll>&catlans){
    cout<<"\nCatlan Numbers are: ";
    for(auto ele:catlans){
        cout<<ele<<" ";
    }
    cout<<"\n";
}

int main(){
    ll t;
    cin>>t;
    vector<ll>catlans;
    getCatlanNumber(catlans);
    //printCatlans(catlans);
    while(t--){
        ll n;cin>>n;
        cout<<catlans[n]<<"\n";    
        
    }
    
    
    return 0;
}
