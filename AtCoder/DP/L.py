import sys
input = sys.stdin.readline


dct = {}
sz = 0 

def fill(lst,n):
    try:
        if n == 1:
            for i in range(0,len(lst)):
                arr = [lst[i]]
                if sz % 2 == 0:
                    dct[hash(((str(arr))))] = -lst[i]
                else:
                    dct[hash(((str(arr))))] = lst[i]
        elif n == 2:
            for i in range(2,len(lst)+1):
                arr = lst[i-2:i]
                dct[hash(((str(arr))))] = max(arr)-min(arr)
                if sz % 2 == 1:
                    dct[hash(((str(arr))))] *= -1
        elif n != sz:
            for i in range(n,len(lst)+1):
                arr = lst[i-n:i]

                if sz % 2 == 0: #player 1 goes first
                    if n % 2 == 0: 
                        dct[hash(((str(arr))))] = max(arr[0]+dct[hash(((str(arr[1:]))))],arr[-1]+dct[hash(((str(arr[:-1]))))])
                    else:
                        dct[hash(((str(arr))))] = min(dct[hash(((str(arr[1:]))))]-arr[0],dct[hash(((str(arr[:-1]))))]-arr[-1])
                else:
                    if n % 2 == 1: 
                        dct[hash(((str(arr))))] = max(arr[0]+dct[hash(((str(arr[1:]))))],arr[-1]+dct[hash(((str(arr[:-1]))))])
                    else:
                        dct[hash(((str(arr))))] = min(dct[hash(((str(arr[1:]))))]-arr[0],dct[hash(((str(arr[:-1]))))]-arr[-1])
        else:
            arr = lst
            
            if sz % 2 == 0: #player 1 goes first
                if n % 2 == 0: 

                    dct[hash(((str(arr))))] = max(arr[0]+dct[hash(((str(arr[1:]))))],arr[-1]+dct[hash(((str(arr[:-1]))))])
                else:

                    dct[hash(((str(arr))))] = min(dct[hash(((str(arr[1:]))))]-arr[0],dct[hash(((str(arr[:-1]))))]-arr[-1])
            else:
                if n % 2 == 1: 

                    dct[hash(((str(arr))))] = max(arr[0]+dct[hash(((str(arr[1:]))))],arr[-1]+dct[hash(((str(arr[:-1]))))])
                else:

                    dct[hash(((str(arr))))] = min(dct[hash(((str(arr[1:]))))]-arr[0],dct[hash(((str(arr[:-1]))))]-arr[-1])
    except KeyError:
        print(n)



n = int(input())
array = [int(i) for i in input().split()]
sz = len(array)

for i in range(1,sz+1):
    fill(array,i)
print(dct[hash(((str(array))))])
