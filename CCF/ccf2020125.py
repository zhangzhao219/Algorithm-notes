n,m = map(int,input().split())

x = [0] * n
y = [0] * n
z = [0] * n

for i in range(m):
    temp = list(map(int,input().split()))
    if temp[0] == 1:
        L,R,xt,yt,zt = temp[1],temp[2],temp[3],temp[4],temp[5]
        for j in range(L-1,R):
            x[j] += xt
            y[j] += yt
            z[j] += zt
    elif temp[0] == 2:
        L,R,p = temp[1],temp[2],temp[3]
        for j in range(L-1,R):
            x[j] *= p
            y[j] *= p
            z[j] *= p
    elif temp[0] == 3:
        L,R = temp[1],temp[2]
        for j in range(L-1,R):
            x[j],y[j],z[j] = y[j],z[j],x[j]
    else:
        L,R = temp[1],temp[2]
        sumx = 0
        sumy = 0
        sumz = 0
        for j in range(L-1,R):
            sumx += x[j]
            sumy += y[j]
            sumz += z[j]
        print((pow(sumx,2) + pow(sumy,2) + pow(sumz,2))%1000000007)


