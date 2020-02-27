def binSearch(array,ele):
    #print(array)
    if array==[]:
        return [-1]

    l=0
    u=len(array)-1
    
    while l<=u:
        m=(l+u)//2
        
        if array[m]==ele:
            return [1,m]
        if array[m]>ele:
            u=m-1
        else:
            l=m+1
    return [-1]

if __name__=="__main__":
    towers=list(map(int,input().split()))
    listeners=list(map(int,input().split()))

    i=0


    while listeners!=[]:
        if i==0:
            for each_tower in range(0,len(towers)):
                ele=towers[each_tower]
                towers[each_tower]=[ele-1,ele+1]
        else:
            for each_tower in range(0,len(towers)):
                ele=towers[each_tower]
                if ele[0]-1<0:
                    ele[0]=0
                else:
                    ele[0]=ele[0]-1
                if ele[1]+1>1000:
                    ele[1]=1000
                else:
                    ele[1]=ele[1]+1
                towers[each_tower]=[ele[0],ele[1]]
        i=i+1
        print("towers array is : ",towers,"and listerners array is :",listeners)
        for each_tower in range(0,len(towers)):
            ele=towers[each_tower]
            
            #print("Element is : ",ele)
            if binSearch(listeners,ele[0])[0]!=-1:
                #print("Searching",ele[0])
                listeners.pop(binSearch(listeners,ele[0])[1])
            #print("First part solved")
            if binSearch(listeners,ele[1])[0]!=-1:
                #print("Searching",ele[1])
                listeners.pop(binSearch(listeners,ele[1])[1])
        
    print(i)
            
"""
10
2 5 3
towers array is :  [[9, 11]] and listerners array is : [2, 5, 3]
towers array is :  [[8, 12]] and listerners array is : [2, 5, 3]
towers array is :  [[7, 13]] and listerners array is : [2, 5, 3]
towers array is :  [[6, 14]] and listerners array is : [2, 5, 3]
towers array is :  [[5, 15]] and listerners array is : [2, 5, 3]
towers array is :  [[4, 16]] and listerners array is : [2, 3]
towers array is :  [[3, 17]] and listerners array is : [2, 3]
towers array is :  [[2, 18]] and listerners array is : [2]
8
"""




