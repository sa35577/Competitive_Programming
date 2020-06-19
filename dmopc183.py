

s1 = input()
s2 = input()
s3 = input()
keys = ["A","A#","B","C","C#","D","D#","E","F","F#","G","G#"]
D = 0
while True:
    a,b,c = keys.index(s1),keys.index(s2),keys.index(s3)
    if (3 <= abs(a-b) <= 4 or 3 <= 12 - abs(a-b) <= 4) and (3 <= abs(b-c) <= 4 or 3 <= 12 - abs(b-c) <= 4):
        break
    s1,s2,s3 = s3,s1,s2
    D += 1
print(s1)
x = abs(a-b)
y = abs(b-c)
if x != 3 and x != 4:
    x = 12 - x
if y != 3 and y != 4:
    y = 12 - y
if x == 3 and y == 3:
    print("diminished")
elif x == 3 and y == 4:
    print("minor")
elif x == 4 and y == 4:
    print("augmented")
else:
    print("major")
if D == 0:
    print("root position")
elif D == 1:
    print("first inversion")
else:
    print("second inversion")

