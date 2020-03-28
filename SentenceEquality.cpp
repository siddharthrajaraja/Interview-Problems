#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<utility>
#include<string.h>

using namespace std;

std::vector<pair<string,string> >pairs;
std::vector<vector<string> >sentences;

void inputPairs();
void printPairs();
void inputSentences();
void splitSentences(string);
void printSentences();




int main(){
    inputPairs();
    printPairs();
    inputSentences();
    printSentences();
    


    return 0;
}


void inputPairs(){
    int n ; std::cout<<"Enter number of pairs of similar words : "; std::cin>>n;

    while(n!=0){
        string s1,s2;std::cin>>s1>>s2;
        pair<string,string>child;
        child.first=s1;
        child.second=s2;
        pairs.push_back(child);
        n--;
    }

}

void printPairs(){
    std::cout<<"\nPairs are :"<<endl;
    for(vector<pair<string,string> >::iterator i =pairs.begin();i!=pairs.end();i++){
        std::cout<< (*i).first << "\t" << (*i).second <<"\n";
    }
}

void splitSentences(string s){
    vector<string>child;

    for(int i=0;i<s.size();){
            int j=i;
        
        if(s[i]!=' '){
            while(j<s.size()){
                if(s[j]==' ')break;
                j++;
            }
            string cpy=s.substr(i,j-i);
            //std::cout<< i<<" "<<j<<"Substring is :" <<cpy <<endl;
            child.push_back(cpy);

        }
        if(i==j)i++;
        else  i=j+1;
    }
    sentences.push_back(child);


}

void inputSentences(){
    fflush(stdin);fflush(stdout);
    
    string sentence1,sentence2;
    std::cout<<"Enter sentence 1 :";  getline(std::cin,sentence1);
    std::cout<<"Enter sentence 2 :";  getline(std::cin,sentence2);
    splitSentences(sentence1);
    splitSentences(sentence2);
}

void printSentences(){
    int count =0;
    for(vector<vector<string> > ::iterator i=sentences.begin();i!=sentences.end();i++){
        vector<string>child=*i;
        std::cout<<"Sentences : "<<count <<" : ";

        for(vector<string>::iterator j=child.begin();j!=child.end();j++){
                std::cout<<*j<<"\t";

        }
        count++;
        std::cout<<endl;
    }
}