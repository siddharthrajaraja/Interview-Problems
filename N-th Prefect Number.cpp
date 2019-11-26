#include<stdio.h>
#define MAX 100000
long long int A[MAX];

int getSum(long n){
	long s=0;
	while(n!=0){
		s=s+(n%10);
		n=n/10;
	}
	if(s==10)return 1;
	return 0;
}

int main(){
	int n;
	scanf("%d",&n);
	int i=0,j=0;
	for(i=0;;i++){
		if(j>1000)break;
		if(getSum(i)==1)A[j++]=i;
	}
	printf("%lld",A[n-1]);
		
	return 0;
}