def getSquare(n):
    s=0
    while n!=0:
        s=s+pow(n%10,2)
        
        n=n//10
    return s

visit=[]

for i in range(0,10001):
    visit.append(0)

visit[0]=1
if __name__=="__main__":
    n=int(input())
    
    while True:
        
        if (n in range(0,10001) and visit[n-1]==1 or set(visit)=={1}):
            break
        if n in range(0,10001):
            
        	visit[n-1]=1
        n=getSquare(n)
        
        #print(n)
    if(n==1):
        
        print("true")
    else:
        print("false")
        
    
    
