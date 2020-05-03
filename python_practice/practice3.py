s = list(input())#1行の文字列の入力。
a = 0

for num in s:
    if num == '1':
        a += 1

print(a)