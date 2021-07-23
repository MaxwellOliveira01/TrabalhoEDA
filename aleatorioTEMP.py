from random import randint as r

n = r(1,100)
print(n)

for _ in range(n):
    print(r(-100,100), end= " ")

print()