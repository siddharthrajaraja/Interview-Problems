#include<bits/stdc++.h>
using namespace std;
#define vN vector<struct trieNode *> 
#define instruct() cout<<"ENTER 1)INSERT 2)SEARCH 3)STARTS-WITH 4)Exit";
#define REP(i,a,b) for(int i=a;i<b;i++)

class Trie {
public:

    
    typedef struct trieNode {

        struct trieNode *next[26]={NULL};
        bool endOfWord;

    }trieNode;

    /** Initialize your data structure here. */

    trieNode x;
    

    Trie() {
        x.endOfWord=false;
    }
    
    void insertWord(trieNode *root,string s){

        trieNode *p=root;
        int index=0;
        int size=s.size();

        for(auto ele:s){
            //cout<<"Element is :"<<ele<<endl;
            
            if(p->next[ele-'a']==NULL){
                
                trieNode *newNode =new trieNode ;
                
                newNode->endOfWord=false;
                
                if(index==size-1)
                    newNode->endOfWord=true;

                p->next[ele-'a']=newNode;

                p=p->next[ele-'a'];



            }
            else{
                if(index==size-1)
                    p->next[ele-'a']->endOfWord=true;
                
                p=p->next[ele-'a'];

            }
            index++;

        }

    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        insertWord(&x,word);
    }
    
    bool searchWord(trieNode *root,string word){

        trieNode *p=root;

        for(auto ele:word){

            if(p->next[ele-'a']!=NULL){
                p=p->next[ele-'a'];
            }
            else{
                return false;
            }


        }
        return p->endOfWord;


    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        return searchWord(&x,word);
    }
    

    bool startWithWord(trieNode *root,string word){
        trieNode *p=root;

        for(auto ele:word){
            if(p->next[ele-'a']==NULL){
                return false;
            }
            p=p->next[ele-'a'];


        }
        return true;

    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {

        return startWithWord(&x,prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
