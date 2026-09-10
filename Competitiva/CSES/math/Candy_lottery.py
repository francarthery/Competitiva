from decimal import Decimal
n, k = input().split()
n, k = int(n), int(k)
 
def calc(x, n): #max dig, largo
    ans = 1
    for i in range(n):
        ans *= x
        
    return ans
 
 
num = 0
for i in range(k):
    num += (calc(i+1, n) - calc(i, n)) * (i+1)
    
ans = str(num * 10000000 // calc(k, n))
sobra = (num * int(10**60) // calc(k, n)) % int(10**53) #pido perdon. no lo logre de vias ortodoxas

if int(ans[-1]) > 5 or int(ans[-1]) == 5 and sobra or ans[-1] == '5' and (int(ans[-2]) % 2 and sobra == 0): ans = str(int(ans) + 10)
    
ans = ans[0:-7] + "." + ans[-7:-1]
print(ans)