typedef long long ll;
using namespace std;

void solve(char input[]) {
	ll R=0;
    ll B=0;
    ll G=0;
    
    for(ll i=0;input[i];i++){
        if(input[i]=='R')R++;
        if(input[i]=='G')G++;
        if(input[i]=='B')B++;
        
    }
    ll i=0;
    while(R!=0){
        input[i]='R';
        R--;
        i++;
    }
    
    while(G!=0){
        input[i]='G';
        G--;
        i++;
    }
    
    while(B!=0){
        input[i]='B';
        B--;
        i++;
    }
    
}

