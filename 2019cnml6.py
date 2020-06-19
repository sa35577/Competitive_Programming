ans = []
tot = 0
for a in range(64):
    for b in range(64):
        for c in range(64):
            s = set()
            s.add(a)
            s.add(b)
            s.add(c)
            bad = False
            for i in ans:
                if s == i:
                    bad = True
                    break
            if not bad:
                ans.append(s)
                tot += 1
                print(tot)

print(len(ans))
            
            
