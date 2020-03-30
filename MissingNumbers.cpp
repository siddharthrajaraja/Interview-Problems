#include <bits/stdc++.h>

using namespace std;

#define MAX 10000001
int visited[MAX]={};

void input(long long n){
    
    while(n!=0){
    	long long ele; std::cin>>ele;
        visited[ele]=1;
        n--;
    }
    
}

void solution(long long n){
    long long i=1;
    while(i<=n){
        if(visited[i]==0)std::cout<<i<<" ";
        i++;
    }
    
    
}

int main(){
    long long n;std::cin>>n;
    
	input(n);
    solution(n);
    
	return 0;
}