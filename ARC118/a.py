import numpy as np
# 入力
t, n = map(int, input().split())
# 周期
p = 100 + t

# 1で初期化
a = np.ones(p, np.bool_)
for x in range(100):
    a[p * x // 100] = 0

# p 以下で、現れない数字のリスト
b = np.where(a)[0]
# 何回目の周期の、何番目か
q, r = divmod(n - 1, t)  # divmod: (a // b, a % b)のタプル、0オリジン
ans = p * q + b[r]
print(ans)
