# スペース区切りの整数を入力
data = list(map(int, input().split()))
# 利益のこれまでの最大値と、株の最小値を保持し、O(n)で求める。
maxv = 0
minv = data[0]
for i in data:
    maxv = max(maxv, i - minv)
    minv = min(minv, i)

print('buy {0}, sell {1}'.format(minv, maxv+minv))