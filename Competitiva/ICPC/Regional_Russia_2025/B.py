x = int(input())

def gauss(n):
    return (n * (n+1)) // 2

# def f(t):
#     lvl = 2 * (t // 5) + (t % 5) // 3
    
#     print("lvl", lvl)
#     print("t", t)
#     detres = lvl // 2
#     dedos = lvl - detres
#     print("detres", detres)
#     print("dedos", dedos)
#     pts = 10*t + gauss(detres) * 3 * 20 + gauss(max(0,dedos-1)) * 2 * 20 * dedos * 10
#     if(t % 5 // 3 > 0 ) : 
#         pts += 3 * (lvl-1) * 10
#         pts += (t % 5 - 3) * (lvl * 10 + 10)
#     else : 
#         pts += t % 5 * lvl * 10
    
#     return lvl, pts
if x == 0:
    print(0, 0)
    exit(0)
    
def f2(lvl):
    return 40 * gauss(lvl//2) + 30 * ((lvl + 1) // 2) * ((lvl + 1) // 2)

l, r = -1, x
while r - l > 1 :
    m = (r+l) // 2
    # lvl, pts = f(m)
    if f2(m) > x: r = m
    else : l = m

# print("FIN", m)
# print(f(r))
# for i in range(10): print(i, f2(i))

piso = f2(l)
while piso < x: piso += 10*(l+1)
lvl = l

l, r = -1, x
while r - l > 1 :
    m = (r+l) // 2
    # lvl, pts = f(m)
    if f2(m) > piso: r = m
    else : l = m
    
if f2(l) == piso: lvl = l

print(lvl, piso)