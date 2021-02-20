#import sys
#input = sys.stdin.readline

N = int(input())
lst = [int(i) for i in input().split()]
lst2 = [int(i) for i in input().split()]

tot = 0
for i in range(N):
    tot += (lst[i]*lst[i+1])*(lst2[i])/2
print(tot)