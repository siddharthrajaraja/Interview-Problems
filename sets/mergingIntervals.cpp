#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define pushb push_back
#define popf pop_front
#define popb pop_back
#define pushf push_front
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define ins insert
#define vsll vector<set<ll>>
#define sll set<ll>

void inputArray(vvll & arr,ll n){
    while(n--){
        ll s,d;cin>>s>>d;
        arr.pushb({s,d});
    }
}

int checkRange(sll setEle,vll vecEle){
    //cout<<"Checking :";
    //cout<<*setEle.begin()<<" "<<vecEle[0]<<" "<<*setEle.rbegin()<<"\n";
    if(*setEle.begin()<=vecEle[0] && vecEle[0]<=*setEle.rbegin())return 1;
    return 0;
}

void printNewMerge(vsll arr){
    for(auto each:arr){
        for(auto every:each){
            cout<<every<<"  ";
        }
        cout<<"\n";
    }
}

vvll merge(vvll arr){
    vsll dummy;
    sll first;
    first.ins(arr[0][0]);
    first.ins(arr[0][1]);
    dummy.pushb(first);

    ll i;
    ll dumSize=0;
    REP(i,1,arr.size()){
        //cout<<"Checked Resukt :"<<checkRange(dummy[dumSize],arr[i])<<"\n";
        if(checkRange(dummy.back(),arr[i])){
            sll backDummy=dummy.back();
            backDummy.insert(arr[i][0]);
            backDummy.insert(arr[i][1]);
            dummy[dumSize]=backDummy;
        }
        else{
            sll firChild;
            firChild.ins(arr[i][0]);
            firChild.ins(arr[i][1]);
            dummy.pushb(firChild);
            dumSize++;

        }

    }

    
    //printNewMerge(dummy); // This is to print the Dummy Soltn obtained!!
    vvll finalArray;

    for(auto each:dummy){
         finalArray.pushb({*each.begin(),*each.rbegin()});
    }

    return finalArray;


}

int main(){

    
    ll n;cin>>n;
    vvll arr;
    inputArray(arr,n);
    sort(arr.begin(),arr.end());
    vvll soltn=merge(arr);

    for(auto each:soltn){
        for(auto every:each){
            cout<<every<<" ";
        }
        cout<<"\n";
    }

    return 0;
}