x=raw_input()
y=raw_input()
print x.split(" ")
print x.split(" ")
x1=float(x.split(" ")[0])
y1=float(x.split(" ")[1])
x2=float(y.split(" ")[0])
y2=float(y.split(" ")[1])
distance = ((y2-y1)**2 + (x2-x1)**2)**.5
print distance
