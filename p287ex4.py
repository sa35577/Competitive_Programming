n = int(input())
for ii in range(n):
    s = input()
    flag = True
    for i in range(len(s)):
        if s[i] == " " and flag:
            print(i+1)
            flag = False
            break
    if flag:
        print(0)