x = int(input())

for a in range(-200, 200):
    for b in range(-200, 200):
        if pow(a, 5) - pow(b, 5) == x:
            print(a, b)
            exit()
