import random
import matplotlib.pyplot as plt
a = []
for i in range(37): a.append(0)

for i in range(int(1e6)):
    sum = 0
    for j in range(6):
        sum += random.randint(1,6)
    a[sum] += 1

plt.plot(a, color='skyblue')

# 4. Mostrar el gráfico en pantalla
plt.show()
# print(a)