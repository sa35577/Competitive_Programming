n = int(input())
x = n
a = n // 25
n = n % 25
b = n // 10
n = n % 10
c = n // 5
n = n % 5
d = n // 1
sti = "%i cents requires %i quarters, %i dimes, %i nickels, %i cents." % (x, a, b, c, d)
lst = sti.split()
if d == 0:
    del lst[9:]
elif d == 1:
    lst[-1] = "cent."
if c == 0:
    del lst[7:9]
elif c == 1:
    lst[-3] = "nickel,"
if b == 0:
    del lst[5:7]
elif b == 1:
    lst[-5] = "dime,"
if a == 0:
    del lst[3:5]
elif a == 1:
    lst[-7] = "quarter,"
sti = ""
for word in lst:
    sti += word
    sti += " "
if sti.count(".") == 0:
    sti = sti[:-2]
    sti += "."
print(sti)