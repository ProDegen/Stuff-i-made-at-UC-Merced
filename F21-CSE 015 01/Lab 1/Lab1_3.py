high = 0;
oc = 0;
ec = 0;
i = 0;

while i < 10:
    num = int(input("please enter a number: "));
    i +=1
    if (num%2)==0:
        ec +=1;
    else:
        oc+=1;
    if num>high:
        high=num;
endh = str(high)
print("highest number: " + endh);
if oc==0:
    print("your entered no odds.");