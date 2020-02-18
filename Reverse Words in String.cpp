#include<string.h>
#include<stdio.h>
#define MAX 1000000
char s[MAX];
int  main(){
	scanf("%[^\n]s",s);
	//puts(s);
	int i=strlen(s)-1;
	int j;
	int end;
    int index=0;
    char ans[strlen(s)];

    while(s[i]==' ' && i>=0)i--;


	while (i>=0){
		j=i;
		int k;
		while (j>=0){
			//printf("%c\n",s[j]);
			if(s[j]==' ')break;
			j--;
		}
		if (i!=strlen(s)-1)ans[index++]=' ';
		//printf("%d",j);
		for(k=j+1;k<=i;k++){
			//printf("%c",s[k]);
            ans[index++]=s[k];

		}
		//printf("\n%d\n",k);
		i=j-1;
		//printf("%d",i);
	}
    puts(ans);
    
	return 0;
}

