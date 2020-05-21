#include<bits/stdc++.h>
using namespace std;
#define MAX  1001
void input(vector<int>&arr,int n);



int main(){

    int t;cin>>t;
    while(t--){

        vector<int>arr;
    int n ;cin>>n;
    input(arr,n);
    
    vector<map<int,int>>arrayOfDict;
    map<int,int>child;
    child[arr[0]]=0;
    arrayOfDict.push_back(child);
    int soltn=0;

    int index=1;

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            int difference=arr[i]-arr[j];
            if(arrayOfDict[j].find(difference)!=arrayOfDict[j].end()){
                // mapped element in previous index
                // get counter 
                map<int,int>previous=arrayOfDict[j];
                int count=0;
                if(previous.find(difference)!=previous.end()){
                    count=(*previous.find(difference)).second;
                }
                
                count++;
                
                if(j==0){
                    map<int,int>inner;
                    inner[difference]=count;
                    arrayOfDict.push_back(inner);
                }
                else{
                    map<int,int>alreadyPresent=arrayOfDict.back();
                    //alreadyPresent[difference]=count;
                    arrayOfDict[i][difference]=count;
                }

            }
            else{
                    // element not found in previous index

                    if(j==0){
                    map<int,int>inner;
                    inner[difference]=1;
                    arrayOfDict.push_back(inner);
                }
                else{
                    map<int,int>alreadyPresent=arrayOfDict.back();
                    arrayOfDict[i][difference]=1;
                
                }



            }
        }
    }

    int max=INT_MIN;
    for(auto each:arrayOfDict){

        for(auto every:each){
            if(max<every.second)
                max=every.second;
            //cout<<every.first<<" "<<<<"\n";
        }

    }

    cout<<max+1<<"\n";


    }
    
    return 0;
}


void input(vector<int>&arr,int n){
    while(n--){
        int ele;cin>>ele;
        arr.push_back(ele);
    }
}