import sys
input = sys.stdin.readline
#sys.setrecursionlimit(1500)
def solve(lst,sofar,val):
    if len(lst) == 1:
        if lst[0] == val:
            return 1
        else:
            return -1
    if solve(lst[1:],sofar,val+lst[0]) > 0:
        return 1
    if solve(lst[1:],sofar,val-lst[0]) > 0:
        return 1
    if val % lst[0] == 0 and solve(lst[1:],sofar,val//lst[0]) > 0:
        return 1
    if solve(lst[1:],sofar,val*lst[0]) > 0:
        return 1
    if sofar != 0:
        '''if sofar % val == 0 and solve(lst,0,sofar//val) > 0:
            return 1'''
        if val % sofar == 0 and solve(lst,0,val//sofar) > 0:
            return 1
        if solve(lst,0,val*sofar) > 0:
            return 1
        if solve(lst,0,val-sofar) > 0:
            return 1
        '''if solve(lst,0,sofar-val) > 0:
            return 1'''
        if solve(lst,0,val+sofar) > 0:
            return 1
    
    if solve(lst[1:],sofar+lst[0],val) > 0:
        return 1
    if solve(lst[1:],sofar-lst[0],val) > 0:
        return 1
    if sofar != 0:
        if sofar % lst[0] == 0 and solve(lst[1:],sofar//lst[0],val) > 0:
            return 1
        if lst[0] % sofar == 0 and solve(lst[1:],lst[0]//sofar,val) > 0:
            return 1
        
        if solve(lst[1:],sofar*lst[0],val) > 0:
            return 1
            
    return -1    
    
def permutations(cur,rem):
    lst = []
    if len(rem) == 0:
        lst.append(cur)
        return lst
    for i in range(len(rem)):
        n = cur + [rem[i]]
        m = rem[0:i] + rem[i+1:]
        for perm in permutations(n,m):
            lst.append(perm)
    return lst


tc = int(input())
for i in range(tc):
    lst = []

    for j in range(4):
        lst.append(int(input()))
    cur = 24
    #combs = [lst]
    combs = permutations([],lst)
    flag = False
    while True:
        for i in combs:
            if solve(i,0,cur) > 0:
                flag = True
                break
        if flag:
            break
        cur -= 1
    print(cur)
