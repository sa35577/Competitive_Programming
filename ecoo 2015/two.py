def printHuge(window, word):
    if len(word) <= window:
        return str(word)
    else:
        print(word[0:window])
        return printHuge(window,word[window:])

    
    

for fkr in range(10):
    n = int(input())
    lst = input().strip().split()
    cur = 0
    s = ""
    while cur != len(lst):
        while s == "":
            if len(lst[cur]) > n:
                s = printHuge(n,lst[cur])
            else:
                s += lst[cur]
            cur += 1
            if cur == len(lst):
                break
        if cur == len(lst):
            if s != "":
                print(s)
            s = ""
            break
        while len(s) <= n:
            if cur == len(lst):
                break
            if len(lst[cur]) + 1 + len(s) <= n:
                s += " "
                s += lst[cur]
                cur += 1
            else:
                print(s)
                s = ""
                break
            if cur == len(lst):
                break
        if cur == len(lst):
            if s != "":
                print(s)
            s = ""
            break
    if s != "":
        print(s)
    print("=====")

            
    
          