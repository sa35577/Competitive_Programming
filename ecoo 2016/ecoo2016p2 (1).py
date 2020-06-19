possible = set()

def bash(sofar, left, avail):
    if left == 0:
        possible.add(sofar)
    else:
        for num in avail:
            # 1-5
            bash(sofar+num, left-1, avail)
            # 6
            bash(sofar*num, left-1, avail)

for i in range(10):
    input().strip()
    nums = [int(num) for num in input().strip().split()]

    cases = [int(num) for num in input().strip().split()]

    buff = ""
    for case in cases:
        
        for num in nums:
            bash(num, 2, nums)

        if case in possible:
            buff+="T"
        else:
            buff+="F"
        possible = set()


    print(buff)
