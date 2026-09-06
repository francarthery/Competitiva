import sys
sys.set_int_max_str_digits(200000)
x = int(input())

x*=9
sumdig, largo = 0, len(str(x))
xstr = [] 

for i in str(x):
    sumdig += int(i)
    xstr.append(int(i)) #lcdtm
    
print(x)
ans = 0
while sumdig > ans:
    for i in range(largo-1, -1, -1):
        dig = xstr[i]
        sumdig -= dig
        dig += 1
        sumdig += dig % 10
        xstr[i] = dig % 10
        if dig != 10: break
    
    ans += 1
    
print(ans)
        