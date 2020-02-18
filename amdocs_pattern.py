
n=int(input())
value=1
array=[]
for i in range(0,n):
    j=0
    l=[]
    while j<=i:
        l.append(value)
        j=j+1
        value+=1
    if i%2!=0:
        l.reverse()
    
    array.append(l)

for i in range(0,len(array)):
    L=array[i]
    l=[]
    for j in range(0,len(L)):
        l.append(L[j])
        if j!=len(L)-1:

            l.append("*")
    array[i]=l
for i in range(0,len(array)):
    for j in range(0,len(array[i])):
        print(array[i][j],end=" ")
    print()

