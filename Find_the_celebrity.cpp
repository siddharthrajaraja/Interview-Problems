#include<iostream>
#include<vector>
#include<map>
#include<string.h>
#include<algorithm>

using namespace std;

std::map<string,vector<string> >relations;
std::map<string,int>indegree;
std::map<string,int>outdegree;

int N=0;

void read(int);
void write();
void printVector(vector<string>);
void getDegree();
void inDegree(vector<string>);
void printDegree(string, map<string,int>);
void getSolution(int);



int main(){
    int n; std::cout<<"Enter number of relations : "; std::cin>>n;
    read(n);
    write();
    getDegree();

    printDegree("indegree",indegree);
    printDegree("outdegree",outdegree);

    getSolution(n);







    return 0;
}


void read(int n){
    
    while(n!=0){
        std::vector<string>child;

        string src,des; std::cin>>src>>des;
        child.push_back(des);
        if(relations.find(src)==relations.end()){
                relations.insert({src,child});
        }
        else{   
                relations[src].push_back(des);//printVector(relations[src]);
            }
        
        indegree.insert({src,0});
        outdegree.insert({src,0});
        indegree.insert({des,0});
        outdegree.insert({des,0});
        n--;
    }


}

void write(){
    std::cout<<"\n"<<"Key" << "\t" << "Value"<<"\n";
    map<string,vector<string> >::iterator i;
    
    i=relations.begin();
    while (i!=relations.end())
    {   std::cout<<i->first<<"\t";
        printVector(i->second);

        i++;
    }
}

void printVector(vector<string>arr){
    for(vector<string>::iterator i=arr.begin();i<arr.end();i++){
        std::cout<<*i<<"\t";
    }
    std::cout<<"\n";

}

void getDegree(){
    std::cout<<"\n";
    for(map<string,vector<string> >::iterator i=relations.begin();i!=relations.end();i++){
        outdegree[i->first]=outdegree[i->first]+i->second.size();
       // std::cout<<"yaha hu "<<i->first;
        //printVector(i->second);
        inDegree(i->second);

    }

}

void inDegree(vector<string>arr){
    for(vector<string>::iterator i=arr.begin();i<arr.end();i++){
        indegree[*i]++;
    }

}

void printDegree( string type, map<string,int>dict){
    std::cout<< type+" map is : \n";
    for(map<string,int>::iterator i=dict.begin();i!=dict.end();i++)
    {
        std::cout<<i->first << "\t" << i->second<<"\n";
    }
}

void getSolution(int n){
    string ans="";

    for(map<string,int>::iterator i=indegree.begin();i!=indegree.end();i++){
        if(indegree[i->first]==indegree.size()-1 && outdegree[i->first]==0)
            {   
                    ans=i->first;break;

            }
    }
    if(ans=="")ans="No Celebrity";
    else ans="Celebrity is : "+ans;
    std::cout<<ans<<"\n";
        


}