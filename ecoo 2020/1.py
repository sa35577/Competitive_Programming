lst = ["C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"]
#      0     1     2    3    4     5    6     7    8     9    10    11 

def valid(notes):
    if not (abs(lst.index(notes[1]) - lst.index(notes[0])) == 4 or abs(lst.index(notes[1]) - lst.index(notes[0])) == 8):
       # print("ffff")
       # print(abs(lst.index(notes[1]) - lst.index(notes[0])))
        return False
    if not (abs(lst.index(notes[2]) - lst.index(notes[1])) == 3 or abs(lst.index(notes[2]) - lst.index(notes[1])) == 9):
       # print("sss")
        return False
    if not (abs(lst.index(notes[3]) - lst.index(notes[2])) == 3 or abs(lst.index(notes[3]) - lst.index(notes[2])) == 9):
       # print("tttt")
        return False

    return True


for bob in range(int(input())):
    notes = input().split()
    if valid(notes):
        print("root")
    else:
        notes1 = [notes[1],notes[2],notes[3],notes[0]]
        #print(notes1)
        if valid(notes1):
            print("third")
        else:
            notes2 = [notes1[1],notes1[2],notes1[3],notes1[0]]
            if valid(notes2):
                print("second")
            else:
                notes3 = [notes2[1],notes2[2],notes2[3],notes2[0]]
                if valid(notes3):
                    print("first")
                else:
                    print("invalid")



