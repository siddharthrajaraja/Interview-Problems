def checkAll(matrix):
    for i in range(0,len(matrix)):
        for j in range(0,len(matrix[i])):
            if matrix[i][j]!=-1:
                return 0
    return 1

def spiral(matrix):
        row=0
        col=len(matrix[0])-1
        
        ans=[]
        while True:
            if checkAll(matrix)==1:
                break
            
            i=row
            j=0
            
            while j<=col:
                ans.append(matrix[i][j])
                #print("First: ",i,j)
                
                #print(ans)
                matrix[i][j]=-1
                j=j+1
            j=j-1
            #print(i,j)
            if len(matrix)>=len(matrix[0]):
                    
                while i<=col or  i<len(matrix):
                    if i==len(matrix)-2:
                        if matrix[i+1][j]==-1:
                            break
                    #print("Second : ",i,j)
                    ans.append(matrix[i][j])

                    #print(ans)
                    matrix[i][j]=-1
                    i=i+1
            else:
                while i<=col and  i<len(matrix):
                    if i==len(matrix)-2:
                        if matrix[i+1][j]==-1:
                            break
                    #print("Second : ",i,j)
                    ans.append(matrix[i][j])

                    #print(ans)
                    matrix[i][j]=-1
                    i=i+1
                
            if i==len(matrix):
                i=i-1
            
            
            #print("at",i,j)
            while j>=row:
                #print("Third: ",i,j)
                ans.append(matrix[i][j])
                #print(ans)
                matrix[i][j]=-1
                j=j-1
                
            j=j+1
            while i>=row:
                #print("Fouth",i,j)
                ans.append(matrix[i][j])
                #print(ans)
                matrix[i][j]=-1
                i=i-1
            #print(ans)
            row=row+1
            col=col-1
        return ans
        
        

if __name__=="__main__":
    R,C=map(int,input().split())
    matrix=[]
    for i in range(0,R):
        matrix.append(list(map(int,input().split())))
    #print(matrix)
    
    ans=spiral(matrix)
    for i in range(0,len(ans)):
        if ans[i]!=-1:
            print(ans[i],end=" ")
    
"""
OUTPUT :

PS D:\PROJECTS\Interview-Problems> python .\spiral_matrix.py
4 4
1 2 3 4
5 6 7 8 
9 10 11 12
13 14 15 16
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10 
PS D:\PROJECTS\Interview-Problems> python .\spiral_matrix.py
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25
1 2 3 4 5 10 15 20 25 24 23 22 21 16 11 6 7 8 9 14 19 18 17 12 13
PS D:\PROJECTS\Interview-Problems> python .\spiral_matrix.py
6 3
1 2 3
4 5 6
7 8 9
10 11 12
13 14 15
16 17 18
1 2 3 6 9 12 15 18 17 16 13 10 7 4 5 8 11 14
PS D:\PROJECTS\Interview-Problems> python .\spiral_matrix.py
5 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
17 18 19 20
1 2 3 4 8 12 16 20 19 18 17 13 9 5 6 7 11 15 14 10
PS D:\PROJECTS\Interview-Problems> python .\spiral_matrix.py
4 5
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
1 2 3 4 5 10 15 20 19 18 17 16 11 6 7 8 9 14 13 12

"""