#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a;i<b;i++)

class Solution {
public:
    int longestValidParentheses(string s) {

        int i;
        int size=s.size();
        stack<pair<char,int>>stk;
        vector<int>vis(size,0);

        REP(i,0,size){
            if(s[i]=='('){
                stk.push({'(',i});
            }
            else{

                if(!stk.empty()){
                    pair<char,int>stkTop=stk.top();
                    stk.pop();
                    vis[i]=1;
                    vis[stkTop.second]=1;
                }

            }
        }

        
        int count=0;
        // cout<<"Vis :";
        // for(auto ele:vis){
        //     cout<<ele<<" ";
        // }
        //cout<<endl;
        i=0;
        while(i<size){
            if(vis[i]){
                int j=i;

                while(j<size){
                    if(!vis[j])break;
                    j++;
                }

                count=max(count,j-i);
                i=j;
            }
            else i++;

        }

        return count;


    }
};
