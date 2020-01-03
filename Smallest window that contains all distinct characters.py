s=list(input())
dis=set(s)

ans=[]
for i in range(0,len(s)-len(dis)+1):
    for j in range(1,len(s)):
        if set(s[i:j+1])==dis:
            ans.append([len(s[i:j+1]),s[i:j+1]])
ans.sort()
print("".join(ans[0][1]))