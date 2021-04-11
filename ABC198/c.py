import numpy as np
import math
r, x, y = map(int, input().split())
a = np.sqrt((x * x + y * y) / (r * r))
if(math.floor(a) == a):
    print(math.floor(a))
else:
    if(math.floor(a) == 0):
        print(2)
    else:
        print(math.floor(a) + 1)
