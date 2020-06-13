#include<bits/stdc++.h>
#include<sstream>

using namespace std;

#define sci(ele) scanf("%d",&ele)
#define scf(ele) scanf("%f",&ele)
#define scd(ele) scanf("%d",&ele)
#define scll(ele) scanf("%lld",&ele)
#define scull(ele) scanf("%ull",&ele)

#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=a;i>=b;i--)

#define pushb push_back
#define pushf push_front 
#define popb pop_back
#define popf pop_front
#define ins insert
#define mp make_pair
#define MAX pow(10,6)+1
#define MOD pow(10,9)+7
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define googleOp(TestCase,String) cout<<"Case #"<<TestCase<<" : "<<String


typedef long long ll;
typedef unsigned long long ull;

void inputArray(vector<ll>&arr,ll);
ll euclidGCD(ll,ll);
ll factorialDP(ll);
ll powerDnC(ll,ll);

ll getWays(vector<ll>coins,int amount){
    vector<vector<ll>>table;
    vector<ll>child;
    ll i;
    
    REP(i,0,amount+1){
        if(i==0)child.pushb(1);
        else
            child.pushb(0);
    }

    table.pushb(child);

    i=1;
    for(auto ele:coins){
        ll price=ele;
        //cout<<price<<" ";
        ll j;
        child={};
        REP(j,0,amount+1){  
            if(j==0)child.pushb(1);
            else if(price>j)child.pushb(table[i-1][j]);
            else child.pushb(table[i-1][j]+child[j-price]);
        }
        table.pushb(child);
        i++;
        /*cout<<"Ways: ";
        for(auto each:child){
            cout<<each<<" ";
        }*/
       // cout<<endl;
    }

    return table[coins.size()][amount];
    



}

int main(){
    fastio
    int amount;cin>>amount;
    int size;cin>>size;
    vector<ll>coins;
    inputArray(coins,size);
    getWays(coins,amount);
    cout<<getWays(coins,amount);
    return 0;
}

void inputArray(vector<ll>&arr,ll n){
    while(n--){
        ll ele;cin>>ele;
        arr.pushb(ele);
    }
}


ll euclidGCD(ll a,ll b){
    while(a!=b){
        if(a>b)a=a-b;
        else b=b-a;
    }
    return a;
}

ll  factorialDP(ll n){
    vector<ll>fact={1};
    ll i;
    ll j=1;
    REP(i,1,n+1){
        fact.pushb(fact.back()*j);
        j++;
        
    }
    return fact.back();
}

ll powerDnC(ll x,ll y){
    if(y==0)return 1;
    if(y%2!=0){
            return x*powerDnC(x,y/2)*powerDnC(x,y/2); 
    }
    else{
        return powerDnC(x,y/2)*powerDnC(x,y/2);
    }

}
