count = 1
stri = "2 "
test = 3
m = int(input())
while count != m:
    sti = ""
    x = 2
    while x*x <= test:
        if test % x == 0:
            sti += str(x)
            break
        x += 1
    if len(sti) < 1:
        stri += str(test)
        stri += " "
        count += 1
        if count%10 == 0:
            stri = stri[:-1]
            stri += "\n"
        
    test += 2
print(stri[:-1])