
for bob in range(int(input())):
    mp = {}
    lst = []
    for cat in range(int(input())):
        for dog in range(int(input())):
            inp = input().split()
            if inp[0] in mp:
                index = mp[inp[0]]
                lst[index].append([int(inp[1]),int(inp[2])])
            else:
                mp[inp[0]] = len(lst)
                lst.append([[int(inp[1]),int(inp[2])]])
    for i in lst:
        i.sort()
    tot = 0
    for puppy in range(int(input())):
        inp = input().split()
        arr = lst[mp[inp[0]]]
        quan = int(inp[1])
        ind = -1
        while quan > 0:
            ind += 1
            if quan > arr[ind][1]:
                tot += arr[ind][0]*arr[ind][1]
                quan -= arr[ind][1]
            else:
                tot += arr[ind][0]*quan
                quan = 0
    print(tot)

