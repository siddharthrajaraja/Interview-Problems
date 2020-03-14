#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<string>
#include<map>

#define MAX 10000000

using namespace std;


int main(){
        string s;std::cin>>s;
        int cx;
        int i=0;
        while(i<s.length()){
            if(s[i]=='x')cx++;
            
            i++;
        }
        i=0;
        int swaps=0;
        while(cx!=0){
            if(s[i]=='y')swaps++;
            cx--;
            i++;
        }
        while(i<s.length()){
            if(s[i]=='x')swaps++;
            i++;
        }

        std::cout<<swaps<<"\n";

        return 0;
}

