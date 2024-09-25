#请使用print函数输出运算结果
import random

print("Hello World")

n = 7
m = 10

while 1:
    a = random.randint(1,n) # 1-7的随机数
    b = random.randint(1,n) # 1-7的随机数
    now = a * n + b
    total = n * n; // 49 10   # (1,1)->(n+1) (n,n)->(n*(n+1))
    now -= n
    c = m * int(total/m) # 49 -> 40
    if now > c:
        continue
    print(now % m + 1) 
    
m * int(total/m) / (n * n) # 40/49

# while 1:
    
#     if b in [1,2]:
#         break

# if b == 1:
#     print(a)
# else:
#     print(a + 5)

# 5/7 * 2/7 = 10/49