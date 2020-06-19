import sys
input = sys.stdin.readline
for bob in range(10):
    rta = input().strip().split()
    r = int(rta[0])
    t = int(rta[1])
    a = rta[2]
    dictionary = {}
    frequencies = {}
    for i in range(r):
        lst = input().strip().split()
        dictionary[lst[0]] = lst[1]
        arr = [0 for i in range(26)]
        for c in lst[1]:
            arr[ord(c)-65] += 1
        frequencies[ord(lst[0])-65] = arr
    first = a[0]
    last = a[-1]
    freq = [0 for i in range(26)]

    for c in a:
        freq[ord(c)-65] += 1
    for i in range(t):
        first = dictionary[first][0]
        last = dictionary[last][-1]
        nfreq = [0 for i in range(26)]
        for j in range(r): #for each character in freq
            x = freq[j] #number of occurences previously
            for k in range(r):#for each character in the frequency map of the character chosen
                nfreq[k] += x*frequencies[j][k]
        freq = nfreq
        
    s = ""
    s += first 
    s += last 
    s += " "
    s += str(sum(freq))
    print(s)