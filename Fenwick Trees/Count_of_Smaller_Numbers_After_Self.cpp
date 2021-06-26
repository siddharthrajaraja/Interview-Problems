#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a;i<b;i++)
#define vi vector<int>

class Solution {
public:

    const int MAX=1e+4+1;
    
    unordered_map<int,int>BIT;


    int twoComplement(int n){
        return n&-n;
    }
    int getParent(int n){
        return n-twoComplement(n);
    }
    int getNext(int n){
        return n+twoComplement(n);
    }

    void update(int n){
        
        while(n<=2*MAX){
            BIT[n]++;
            n=getNext(n);
        }

    }

    int query(int n){
        int sum=0;
        while (n>0)
        {
            sum+=BIT[n];
            n=getParent(n);
            /* code */
        }
        return sum;
    }

    vector<int> countSmaller(vector<int>& nums) {

        int size=nums.size();

        int i=size-1;
        vector<int>ans;

        while (i>=0)
        {
            nums[i]+=MAX;
            ans.push_back(query(nums[i]-1));

            update(nums[i]);
            
            
            i--;
            /* code */
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;

        
    }
};