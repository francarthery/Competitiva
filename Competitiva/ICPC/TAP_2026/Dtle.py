import sys
sys.set_int_max_str_digits(200000)
x = int(input()) #prueba de TLE

size = len(str(x))

nums = [0]
for i in range(size+1):
    nuevo = nums[-1]
    nuevo = nuevo * 10 + 1
    nums.append(nuevo)
    
ans = 0
for i in range(size, 0, -1):
    while x >= nums[i]: 
        x -= nums[i]
        ans += 1
        
print(ans)