#include<stdio.h>
#define MAX 100000

long long int A[MAX];

void get(long long int n){
	long long int i;
	for(i=0;i<n;i++){
		scanf("%lld",&A[i]);
	} 
}


void set(long long int n){
	long long int i;
	for(i=0;i<n;i++){
		printf("%lld",A[i]);
	} 
}


int binSearch(long long int n,long long int ele){
		long long int l=0,u=n-1;
		
		while(l<=u){
			long long int m=(l+u)/2;
			if (A[m]==ele)return m;
			else if(A[m]>ele)u=m-1;
			else l=m+1;
		}
		return -1;
}



int main(){
	long long int n;
	scanf("%lld",&n);
	get(n);
	long long int ele;
	scanf("%lld",&ele);
	
	if(binSearch(n,ele)!=-1){
			printf("%d",binSearch(n,ele));
	}	
	else{
		printf("\n-1");
	}
		
	
	return 0;
}
