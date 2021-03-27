import numpy as np
n = int(input())
x0, y0 = map(int, input().split())
xn, yn = map(int, input().split())
xm =(x0 + xn) / 2
ym = (y0 + yn) / 2
theta = 2 * np.pi / n
x = (x0-xm) * np.cos(theta) - (y0-ym) * np.sin(theta) + xm
y = (x0-xm) * np.sin(theta) + (y0-ym) * np.cos(theta) + ym
print(x, " ", y)