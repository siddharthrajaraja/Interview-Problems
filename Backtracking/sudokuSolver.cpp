/*
    Time Complexity : O(9^m)
    Space Complexity : O(9*9)
*/
#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a;i<b;i++)
#define vi vector<int>
#define vvi vector<vi>
#define vc vector<char>
#define vvc vector<vc>
#define umap unordered_map

class Solution {
public:

    umap<string,umap<int,bool>>subMatValues;
    vvi grid;
    umap<int,umap<int,bool>>rowValues;
    umap<int,umap<int,bool>>colValues;
    deque<vector<int>>emptyCells;
    int emptyCellsCount;

    void updateGrid(vvc board){
        
        emptyCells={};
        emptyCellsCount=0;


        grid=vvi(9,vi(9,-1));
        int count=0;

        int i;
        REP(i,0,9){
            int j;
            REP(j,0,9){
                if(board[i][j]!='.'){
                    grid[i][j]=board[i][j]-'0';
                    rowValues[i][grid[i][j]]=true;
                    colValues[j][grid[i][j]]=true;
                    string subMatIndex=getSubmatIndex(count);
                    subMatValues[subMatIndex][grid[i][j]]=true;
                }
                else{
                    emptyCellsCount++;
                    emptyCells.push_back({i,j,count});
                }
                count++;
            }
        }
    }

    string getSubmatIndex(int position){
        int row=position/9;
        int col=position%9;
        int R;
        int C;

        if(row>=0&&row<=2)R=0;
        else if(row>=3&&row<=5)R=1;
        else R=2;
        

        if(col>=0&&col<=2)C=0;
        else if(col>=3&&col<=5)C=1;
        else C=2;

        return to_string(R)+to_string(C);

    }

    void printBoard(vvi board){
        cout<<"Board :\n";
        for(auto ele:board){
            for(auto every:ele){
                cout<<every<<" ";
            }
            cout<<endl;
        }
    }

    bool reached;
    int index;
    

    vvi ansBoard;


    void dfs(int index){
        if(!reached){

            if(index==emptyCellsCount){
                
                ansBoard=grid;
                //printBoard(grid);

                return ;

            }

            int x=emptyCells[index][0];
            int y=emptyCells[index][1];
            int count=emptyCells[index][2];

            int i ;

            REP(i,1,10){
                if(!rowValues[x][i]&&!colValues[y][i]&&!subMatValues[getSubmatIndex(count)][i]){
                    rowValues[x][i]=true;
                    colValues[y][i]=true;
                    subMatValues[getSubmatIndex(count)][i]=true;

                    grid[x][y]=i;

                    dfs(index+1);
                    
                    grid[x][y]=-1;
                    rowValues[x][i]=false;
                    colValues[y][i]=false;
                    subMatValues[getSubmatIndex(count)][i]=false;
                    
                }
            }

        }

    }

    void solveSudoku(vector<vector<char>>& board) {
        updateGrid(board);
        reached=false;
        index=0;
        //printBoard(grid);
        //cout<<endl;
        dfs(index);

        int i;
        REP(i,0,9){
            int j;
            REP(j,0,9){

                board[i][j]=(char)(ansBoard[i][j]+'0');
                
            }

        }


    }
};