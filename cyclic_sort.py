"""
sorted :
0 1 2 3 4 5
1 2 3 4 5 6  

0 1 2 3 4 5
5 3 4 1 6 2
num-1=index

cyclic sort
"""

arr=[5,3,4,1,6,2]
i=0
while(i<len(arr)):
    if arr[i] - 1 == i:
        i+=1
    else:
        temp = arr[arr[i]-1]
        arr[arr[i]-1]=arr[i]
        arr[i]=temp
    iterations+=1
print(arr)
