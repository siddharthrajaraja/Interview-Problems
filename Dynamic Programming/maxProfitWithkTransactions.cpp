#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,a,b) for(ll i=a;i<b;i++)

int maxProfitWithKTransactions(vector<int> prices, int opp) {
    ll transactions=opp;
		ll n=prices.size();
	if(n==0)return 0;
	  vector<ll>preRow(n,0);
    vector<vector<ll>>profit(transactions+1,preRow);


    ll i;

    REP(i,1,transactions+1){
        ll j;
        REP(j,1,n){
            ll k;
            ll index=0;
            ll maxi=INT_MIN;

            REP(k,0,j){
                if(maxi<(prices[j]-prices[k]+profit[i-1][k])){
                    maxi=(prices[j]-prices[k]+profit[i-1][k]);
                }
            }

            profit[i][j]=max(profit[i][j-1 ],maxi);

        }
    }

    /*for(auto each:profit){
        for(auto every:each){
            cout<<every<<" ";
        }
        cout<<endl;
    }
  */
	
	//	cout<<profit[transactions][n-1]<<"\n";
  	
	 
	return profit[transactions][n-1];
}
