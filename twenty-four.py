import sys
input = sys.stdin.readline
#sys.setrecursionlimit(1500)

st = set()

def solve(lst,sofar,val):
    if val < 0 or hash(((str(lst),sofar,val))) in st:
        return False
    if len(lst) == 0 and sofar == 0:
        if val == 0:
            #print(lst,sofar,val)
            return True
        else:
            return False
    if len(lst) > 0:
        if solve(lst[1:],sofar,val+lst[0]) :
            #print(lst,sofar,val)
            return True
        if solve(lst[1:],sofar,val-lst[0]) :
            #print(lst,sofar,val)
            return True
        if val != 0 and val % lst[0] == 0 and solve(lst[1:],sofar,val//lst[0]) :
            #print(lst,sofar,val)
            return True
        if val != 0 and solve(lst[1:],sofar,val*lst[0]) :
            #print(lst,sofar,val)
            return True
    if sofar != 0:
        '''if sofar % val == 0 and solve(lst,0,sofar//val) :
            return True'''
        if val != 0 and val % sofar == 0 and solve(lst,0,val//sofar) :
            #print(lst,sofar,val)
            return True
        if val != 0 and solve(lst,0,val*sofar) :
            #print(lst,sofar,val)
            return True
        if solve(lst,0,val-sofar) :
            #print(lst,sofar,val)
            return True
        '''if solve(lst,0,sofar-val) :
            return True'''
        if solve(lst,0,val+sofar) :
            #print(lst,sofar,val)
            return True
    if len(lst) > 0:
        if solve(lst[1:],sofar+lst[0],val) :
            #print(lst,sofar,val)
            return True
        if solve(lst[1:],sofar-lst[0],val) :
            #print(lst,sofar,val)
            return True
        if sofar != 0:
            if sofar % lst[0] == 0 and solve(lst[1:],sofar//lst[0],val) :
                #print(lst,sofar,val)
                return True
            if lst[0] % sofar == 0 and solve(lst[1:],lst[0]//sofar,val) :
                #print(lst,sofar,val)
                return True
            
            if solve(lst[1:],sofar*lst[0],val) :
                #print(lst,sofar,val)
                return True
    st.add(hash((str(lst),sofar,val)))
    return False    
    
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
            if solve(i,0,cur):
                flag = True
                break
        if flag:
            break
        cur -= 1
    print(cur)
    st.clear()
