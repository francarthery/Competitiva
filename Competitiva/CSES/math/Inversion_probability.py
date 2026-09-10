from fractions import Fraction
n = int(input())
v = list(map(int, input().split()))
 
# print(v)
 
prod = 1
for i in range(n): prod *= v[i]
 
num = 0
for i in range(n):
    for j in range(i, n):
        if i == j: continue
        cant = 0
        for k in range(v[i]):
            cant += min(k, v[j])
        
        num += ((prod // v[i]) // v[j]) * cant
 
ans = Fraction(num, prod)
ans = float(round(ans, 6))
print(f"{ans:.6f}")