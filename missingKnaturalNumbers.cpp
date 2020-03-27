#include <bits/stdc++.h>
#include<iostream>
#include<set>
#include<algorithm>

using namespace std;

std::set<unsigned long long>arr;


void insert(long long n){
    while (n!=0){
	    long long ele;
        std::cin>>ele;
        if(ele>0){
            arr.insert(ele);
        }
        n--;
    }
}

void printSet(){
    for(set<unsigned long long>::iterator i=arr.begin();i!=arr.end();i++)std::cout<<*i<<"\t";

}

void missingKnaturalNumbers(int k){
    unsigned long long i=1;

    while(k!=0){
        if(!binary_search(arr.begin(),arr.end(),i)){
            std::cout<<i<<" ";
            k--;
        }
        i++;
    }

}

int main(){
    long long n ; std::cin>>n;
    insert(n);
   // printSet();
    int k ; std::cin>>k;
    missingKnaturalNumbers(k);
    return 0;
}