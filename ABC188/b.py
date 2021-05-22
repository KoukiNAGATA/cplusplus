import numpy as np
n = int(input())
a = np.array(list(map(int, input().split())))
b = np.array(list(map(int, input().split())))
if (np.dot(a, b)):
    print('No')
else:
    print('Yes')
