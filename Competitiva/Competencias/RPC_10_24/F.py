c1, m1, c2, m2 = map(int, input().split())

if c1 == 0 or m1 == 0 or c2 == 0 or m2 == 0:
    print(0)
    exit(0)

m1 += c1
m2 += c2

if c1 * m2 > c2 * m1:
    c1, c2, m1, m2 = c2, c1, m2, m1

c3, m3, cont = (c2 * 2) // m2, 2, 1

while c3 * m1 < c1 * m3:
    m3 = m3 * 2
    c3 = (c2 * m3) // m2
    cont += 1

print(cont)