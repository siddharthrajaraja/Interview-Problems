n=int(input())
l=list(map(int,input().split()))

k=int(input())

for i in range(0,len(l)-k+1):
    m=l[i:i+k]
    #print(m)
    flag=0
    for j in range(0,len(m)):
        if m[j]<0:
            print(m[j],end=" ")
            flag=1
            break
    if flag!=1:
        print(0,end=" ")