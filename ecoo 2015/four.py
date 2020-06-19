lit = ["ook","ookook","oog","ooga","ug","mook","mookmook","oogam","oogum","ugug"]
for bob in range(10):
    sti = input().strip()
    lst = [0 for i in range(len(sti)+1)]
    lst[0] = 1
    if len(sti) < 3:
        print(0)
    else:
        for i in range(len(sti)+1):
            for j in lit:
                try:
                    if sti[i-len(j):i] == j:
                        lst[i] += lst[i-len(j)]
                except:
                    pass
    print(lst[-1])
