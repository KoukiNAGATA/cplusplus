import math

a, b, h, m = map(int, input().split())
x = a*(math.cos(math.radians(30*h+0.5*m)))-b*(math.cos(math.radians(6*m)))
y = a*(math.sin(math.radians(30*h+0.5*m)))-b*(math.sin(math.radians(6*m)))
ans = math.sqrt(x**2+y**2)
print(ans)