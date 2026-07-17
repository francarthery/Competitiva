import math

def is_prime_quick(n: int) -> bool:
    if n <= 1: 
        return False
    return all(n % i != 0 for i in range(2, int(math.sqrt(n)) + 1))

t = int(input())



while t:
    n = int(input())
    x = []
    for i in range(3,300):
        if (n + (1<<i)) % i == 0:
            x.append(i)
    
    if(len(x) > 0):
        for i in x:
            if(is_prime_quick(i)):
                print(i)
    else:
        print("-1")
        
    t-=1