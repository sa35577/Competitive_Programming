firstStraight = 0
secondStraight = 0
x1,y1,x2,y2 = map(float,input().split())
x3,y3,x4,y4 = map(float,input().split())
if x1 == x2:
    firstStraight = 1
if x3 == x4:
    secondStraight = 1
if firstStraight + secondStraight == 2:
    if x1 == x3:
        print("coincident")
    else:
        print("parallel")
else:
    if firstStraight == 1:
        secondSlope = (y4-y3)/(x4-x3);
        secondInter = y4-secondSlope*x4;
        print("%f %f"%(x1,secondSlope*x1+secondInter))
    elif secondStraight == 1:
        firstSlope = (y2-y1)/(x2-x1);
        firstInter = y1-firstSlope*x1;
        print("%.10f %.10f"%(x3,firstSlope*x3+firstInter))
    else:
        firstSlope = (y2-y1)/(x2-x1);
        firstInter = y1-firstSlope*x1;
        secondSlope = (y4-y3)/(x4-x3);
        secondInter = y4-secondSlope*x4;
        if (firstSlope == secondSlope and firstInter == secondInter):
            print("coincident")
        elif (firstSlope == secondSlope):
            print("parallel");
        else:
            interY = (firstInter*secondSlope-secondInter*firstSlope)/(secondSlope-firstSlope);
            interX = (interY-firstInter)/firstSlope
            print("%f %f"%(interX,interY))
