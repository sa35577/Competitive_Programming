def asc(c):
    return ord(c)-97
def invasc(x):
    return chr(x+97)
def base26(x):
    a = x//26
    b = x%26
    out = invasc(a) + invasc(b)
    return out
def cipher(c,turn):
    x = asc(c)
    x = (x + turn) % 26
    return invasc(x)

for bob in range(10):
    k = int(input())
    s = input().split()
    t = base26(len(s))
    for i in s:
        u = base26(len(i))
        if u[0] == "a":
            t += u[1]
        else:
            t += u
    print(t)
    lst = [k for i in range(len(t))]
    for i in range(len(lst)-2,-1,-1):
        lst[i] += (lst[i+1] + asc(t[i+1])) % 26
    for i in range(len(t)):
        print(cipher(t[i],lst[i]-1),end="")
    
    for dad in s:
        t = dad
        lst = [k for i in range(len(t))]
        for i in range(len(lst)-2,-1,-1):
            lst[i] += (lst[i+1] + asc(t[i+1])) % 26
        for i in range(len(t)):
            print(cipher(t[i],lst[i]-1),end="")

    print()


