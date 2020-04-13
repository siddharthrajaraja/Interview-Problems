#include<bits/stdc++.h>
typedef long long ll;

using namespace std;

void encode(string);
void decode(string);


int main() {
	ll choice ;cin>>choice;fflush(stdin);fflush(stdout);
    string s;cin>>s;
    
    switch(choice){
        case 1:	
            	encode(s);
            	break;
        case 2:
            	decode(s);
            	
            	break;
            
        
            
    }

	return 0;
}

void encode(string s){
    
    for(int i=0;s[i];){
        int j=i;
        int count=0;
        for(;s[j];j++){
            if(s[i]!=s[j])break;
            count ++;
        }
        cout<<count<<s[i];
        
        i=j;
    }
    
}


void decode(string s){
    string ans="";
     
    for(int i=0;s[i];){
        int number=0;
         int j=i;
        if(isdigit(s[i])){
           
            int count=0;
            for(;s[j];j++){
                if(!isdigit(s[j]))break;
                
                number=number*10+(s[j]-'0');
            }
            //cout<<number<<endl;

            
        }
        if(number==0)
        		i++;
        else{
            i=j+1;
        }
        
         while(number!=0){
            ans+=s[j];
            number--;
        }
       
        
        
        
        
    }
    
    cout<<ans<<endl;
    
}
