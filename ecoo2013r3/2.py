for boob in range(10):
    s1 = list(input().strip())
    s2 = list(input().strip())
    s3 = list(input().strip())
    n = len(s1)
    mut = 0
    for i in range(n):
        if s1[i] == s2[i] and s1[i] != s3[i]:
            mut += 1
            s1[i] = s3[i]
            s2[i] = s3[i]
    ###parent 1 dominates
    mut1 = mut
    if s1[0] != s3[0]:
        mut1 += 1
        s1[0] = s3[0]
    if s1[-1] != s3[-1]:
        mut1 += 1
        s1[-1] = s3[-1]
    
    ind = 0
    lst = []
    while ind < n:
        while s1[ind] == s3[ind]:
            ind += 1
            if ind == n:
                break
        if ind == n:
            break
        lst.append([ind,0])
        while s1[ind] != s3[ind]:
            ind += 1
            lst[-1][1] += 1
            if ind == n:
                break
        if ind == n:
            break
    

    ###parent 2 dominates
    mut2 = mut
