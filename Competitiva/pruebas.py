import math
a, b, c, d = map(int, input().split())

if a < b: a, b = b, a
if c < d: c, d = d, c

theta = math.atan(b/a)
ok = True

l1 = math.cos(theta) * c
h1 = math.sin(theta) * c
h2 = math.cos(theta) * d
if b < h1 + h2: ok = False

l3 = math.sin(theta) * d
if l1 + l3 > a: ok = False

if ok : print("YES")
else : print("NO")

"""     if(a < b) swap(a, b);
    if(c < d) swap(c, d);

    ld theta = atanl(b/a);
    bool ok = true;
    
    ld l1 = cosl(theta) * c;
    ld h1 = sinl(theta) * c;
    ld h2 = cosl(theta) * d;
    if(b < h1 + h2) ok = false;

    ld l3 = sinl(theta) * d;
    if(l1 + l3 > a) ok = false;

    cout << (ok ? "YES" : "NO") << '\n';

    return 0;
} """