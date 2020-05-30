import sys
# スペース区切りの整数を3行まとめて入力
data = [sys.stdin.readline().rstrip().split() for _ in range(3)]
# 行、列の組み合わせ6通りについて調べる
# 列
for i in range(3):
    if(data[0][i] == data[1][i] or data[0][i] == data[2][i] or data[1][i] == data[2][i]):
        print("invalid")
        sys.exit()
# 行
for i in range(3):
    if(data[i][0] == data[i][1] or data[i][0] == data[i][2] or data[i][1] == data[i][2]):
        print("invalid")
        sys.exit()

# 重複無し
print("valid")