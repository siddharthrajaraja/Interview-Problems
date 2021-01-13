#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<ll>
typedef long long ll;
#define REP(i, a, b) for (int i = a; i < b; i++)
#define MOD 1000000007




class Solution
{
public:
    int fenTree[1000000]={0};

    
    
    
    void printFenTree(vll arr){
        cout<<"FenTree is :";
        for(auto ele:arr){
            cout<<ele<<" ";
        }
        cout<<endl;
        
    }
    
    int getTwoComplement(int ele)
    {
        return ele & (-1 * ele);
    }

    int getParent(int index)
    {
        int twoComplement = getTwoComplement(index);
        int andIndex = index & twoComplement;
        return index - andIndex;
    }

    int getNext(int index)
    {
        int twoComplement = getTwoComplement(index);
        int andIndex = index & twoComplement;
        return index + andIndex;
    }

    void updateFenTree(int ele, int n,int size)
    {

        int fenIndex = ele + 1;
        
        while (fenIndex <size)
        {
         //   cout<<fenTree.size() <<" " <<fenIndex<<" "<<n<<endl;
            fenTree[fenIndex]++;
            fenIndex = getNext(fenIndex);
        }
       // cout<<"exit\n";
    }

    long long int getSumFenTree(int ele)
    {

        int fenIndex = ele + 1;
        long long int sum = 0;

        while (fenIndex > 0)
        {
            sum += fenTree[fenIndex];
            fenIndex = getParent(fenIndex);
        }

        return sum;
    }

    int createSortedArray(vector<int> &instructions)
    {

        int maxi = *max_element(instructions.begin(), instructions.end());
        
        vll fenTree(maxi + 2, 0);
        int size=maxi+2;
        long long int sum = 0;

        for (auto ele : instructions)
        {
            
            //printFenTree(fenTree);
            sum = (sum+min(getSumFenTree(ele-1), getSumFenTree(maxi) - getSumFenTree(ele)))%MOD;
            
            updateFenTree(ele, maxi,size);
        }

        return sum;
    }
};
