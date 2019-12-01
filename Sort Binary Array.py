n=int(input())

l=list(map(int,input().split()))

ones=0
zeroes=0

for i in range(0,len(l)):
    if l[i]==0:
        zeroes+=1
    else:
        ones+=1

ans=list('0'*zeroes+'1'*ones)
print(" ".join(ans))
