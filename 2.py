def isUpper(c):
    return ord(c) >= 65 and ord(c) <= 90
def isLower(c):
    return ord(c) >= 97 and ord(c) <= 122
def isNumber(c):
    return ord(c) >= 48 and ord(c) <= 57
def isSymbol(c):
    if isNumber(c) or isLower(c) or isUpper(c):
        return False
    return True
def isLetter(c):
    return isUpper(c) or isLower(c)





for bob in range(10):
    s = input().strip()
    tot = 0
    tot += 4*len(s)
    #print(tot)
    types = [0 for i in range(4)]
    freq = [0 for i in range(4)]
    uppers = []
    lowers = []
    digits = []
    letters = []
    #upper,lower,number,symbol
    for i in range(len(s)):
        c = s[i]
        if isUpper(c):
            types[0] = 1
            freq[0] += 1
            uppers.append(i)
            letters.append(i)
        elif isLower(c):
            types[1] = 1
            freq[1] += 1
            lowers.append(i)
            letters.append(i)
        elif isNumber(c):
            types[2] = 1
            freq[2] += 1
            digits.append(i)
        else:
            types[3] = 1
            freq[3] += 1
    if sum(types) >= 3:
        tot += 2 + 2 *sum(types)
    #print(tot)
    if freq[0] > 0:
        tot += (len(s)-freq[0])*2
    #print(tot)
    if freq[1] > 0:
        tot += (len(s)-freq[1])*2
    #print(tot)
    if freq[2] != len(s):
        tot += 4*freq[2]
    #print(tot)
    tot += 6*freq[3]
    #print(tot)

    tot += 2*(freq[2]+freq[3])
    if not (isLetter(s[0])):
        tot -= 2
    if not (isLetter(s[-1])):
        if len(s) > 1:
            tot -= 2
    #print(tot)
    
    if freq[0]+freq[1] == len(s):
        tot -= len(s)
    #print(tot)
    if freq[2] == len(s):
        tot -= len(s)
    #print(tot)
    
    ind = 0
    cons = 0
    while ind < len(uppers):
        cons = 1
        ind += 1
        while ind < len(uppers):
            if uppers[ind]-uppers[ind-1] == 1:
                cons += 1
                ind += 1
            else:
                break
        if cons > 1:
            tot -= 2*(cons-1)
        if ind == len(uppers):
            break
        
    #print(tot)
    ind = 0
    cons = 0
    while ind < len(lowers):
        cons = 1
        ind += 1
        while ind < len(lowers):
            if lowers[ind]-lowers[ind-1] == 1:
                cons += 1
                ind += 1
            else:
                break
        if cons > 1:
            tot -= 2*(cons-1)
            
        if ind == len(lowers):
            break
        
    #print(tot)
    ind = 0
    cons = 0
    
    while ind < len(digits):
        cons = 1
        ind += 1
        while ind < len(digits):
            if digits[ind]-digits[ind-1] == 1:
                cons += 1
                ind += 1
            else:
                break
        if cons > 1:
            tot -= 2*(cons-1)
            
        if ind == len(digits):
            break
        
    #print(tot)
    mxLetters,mxDigits = 0,0
    ind = 0
    cons = 0
    sign = 0
    while ind < len(digits):
        cons = 1
        ind += 1
        sign = 0
        while ind < len(digits):
            #print(digits[ind])
            if digits[ind]-digits[ind-1] == 1 and abs(ord(s[digits[ind]])-ord(s[digits[ind-1]])) == 1:
                if sign == 0:
                    sign = ord(s[digits[ind]])-ord(s[digits[ind-1]])
                if ord(s[digits[ind]])-ord(s[digits[ind-1]]) == sign:
                    cons += 1
                    ind += 1
                else:
                    break
            else:
                break
        if cons > 1:
            mxDigits = max(mxDigits,cons)
        if ind == len(digits):
            break
    #print(tot)
    #print(mxDigits,end = ' ')
    sign = 0
    ind = 0
    cons = 0
    while ind < len(letters):
        cons = 1
        ind += 1
        sign = 0
        while ind < len(letters):
            if letters[ind]-letters[ind-1] == 1 and abs(ord(s[letters[ind]])-ord(s[letters[ind-1]])) == 1:
                if sign == 0:
                    sign = ord(s[letters[ind]])-ord(s[letters[ind-1]])
                if ord(s[letters[ind]])-ord(s[letters[ind-1]]) == sign:
                    cons += 1
                    ind += 1
                else:
                    break
            else:
                break
        if cons > 1:
            mxLetters = max(mxLetters,cons)
        if ind == len(letters):
            break
    #print(mxLetters)
    #print(tot)
    if mxLetters > 2:
        tot -= 3*(mxLetters-2)
    #print(tot)
    if mxDigits > 2:
        tot -= 3*(mxDigits-2)

    


    #print(tot)
    if tot < 0:
        tot = 0
    if tot > 100:
        tot = 100
    

    if tot <= 20:
        print("Very Weak (score = %d)"%tot)
    elif tot <= 40:
        print("Weak (score = %d)"%tot)
    elif tot <= 60:
        print("Good (score = %d)"%tot)
    elif tot <= 80:
        print("Strong (score = %d)"%tot)
    else:
        print("Very Strong (score = %d)"%tot)

    


    
    
        

    


    