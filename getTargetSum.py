def countingSort(array):
    dic={}
    for i in range(0,len(array)):
        if array[i] not in dic:
            dic[array[i]]=1
        else:
            dic[array[i]]+=1
    return dic

def getResult(arrayDic1,arrayDic2,target):
    ans=[]
    for key in arrayDic1.keys():
        if target_sum-key in arrayDic2:
            return True
    return False
if __name__=="__main__":
    arr1=list(map(int,input().split()))
    arr2=list(map(int,input().split()))
    target_sum=int(input())
    arrayDic1=countingSort(arr1)
    arrayDic2=countingSort(arr2)
    print(getResult(arrayDic1,arrayDic2,target_sum))
            
            
        
    
