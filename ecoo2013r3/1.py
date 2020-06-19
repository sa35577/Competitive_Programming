for bob in range(10):
    lst = input().strip().split()
    out = []
    s = lst[0]
    lbrac = 0; rbrac = len(s)-1
    if s.count('[') == 0:
        for dog in range(1,len(lst)):
            if lst[dog] == lst[0]:
                out.append("true")
            else:
                out.append("false")
        print(" ".join(out))
    else:
        s = lst[0]
        for dog in range(1,len(lst)):
            s = lst[0]
            t = lst[dog]
            flag = False
            while s.find('[') != -1:
                ##print(s)
                ##print(t)
                lbrac = s.find('[')
                if len(t) <= lbrac:
                    flag = True
                    ##print('a')
                    break
                if s[:lbrac] != t[:lbrac]:
                    flag = True
                    ##print('b')
                    break
                s = s[lbrac+1:]
                t = t[lbrac:]
                ##print(s)
                ##print(t)
                rbrac = s.find(']')
                freq = [0 for i in range(26)]
                for c in s[:rbrac]:
                    freq[ord(c)-97] += 1
                
                num = (rbrac+1)//2
                if len(t) < num:
                    flag = True
                    ##print('c')
                    break
                ##print(rbrac)
                ##print(num)
                ##print(s)
                ##print(t)
                ##print(freq)
                for c in t[:num]:
                    freq[ord(c)-97] -= 1
                ##print(freq)
                for i in freq:
                    if i < 0:
                        flag = True
                        ##print('d')
                        break
                if flag:
                    break
                s = s[rbrac+1:]
                t = t[num:]
                ##print(s)
                ##print(t)

            if flag:
                out.append("false")
                continue
            if s == t:
                out.append("true")
            else:
                ##print('e')
                out.append("false")

        print(' '.join(out))    
    


