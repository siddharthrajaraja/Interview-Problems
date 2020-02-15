import numpy as np
L=[]
n=int(input("Enter Dimensions of chessboard: "))
for i in range(0,n):
    if i==0:
        
        L.append(list(map(int,"1"*n)))
    else:
        L.append(list(map(int,"0"*n)))

for i in range(0,n):
    L[i][0]=1
L=np.array(L)
print("BEFORE : \n", L)

i=1
while i<n:
    j=1
    while j<n:
        L[i][j]=L[i-1][j]+L[i][j-1]
        j=j+1
    i=i+1
print("AFTER : \n", L)
print("Number of paths : ",L[-1][-1])

"""
OUTPUT : 
Enter Dimensions of chessboard: 8
BEFORE : 
 [[1 1 1 1 1 1 1 1]
 [1 0 0 0 0 0 0 0]
 [1 0 0 0 0 0 0 0]
 [1 0 0 0 0 0 0 0]
 [1 0 0 0 0 0 0 0]
 [1 0 0 0 0 0 0 0]
 [1 0 0 0 0 0 0 0]
 [1 0 0 0 0 0 0 0]]
AFTER : 
 [[   1    1    1    1    1    1    1    1]
 [   1    2    3    4    5    6    7    8]
 [   1    3    6   10   15   21   28   36]
 [   1    4   10   20   35   56   84  120]
 [   1    5   15   35   70  126  210  330]
 [   1    6   21   56  126  252  462  792]
 [   1    7   28   84  210  462  924 1716]
 [   1    8   36  120  330  792 1716 3432]]
Number of paths :  3432

"""
