import requests
url = "https://ob6la3c120.execute-api.ap-northeast-1.amazonaws.com/Prod/battle/"

monster = ["dragon", "griffin", "medusa", "troll", "vampire"]
# keyに名前、valueとして勝った数を持つ辞書を用意
ans = {"dragon":0, "griffin":0, "medusa":0, "troll":0, "vampire":0}

# 5C2 = 10通り戦わせる
for i in range(5):
  for j in range(i+1,5):
    payload = {"key1":"value1", "key2":"value2"}
    r = requests.get(url + monster[i] + "+" + monster[j], params=payload)
    result = r.json()
    # 勝者の値を1足す
    ans[result["winner"]] += 1

# 勝った数についてsortし、返ってきたlistからkeyを出力
for k, v in sorted(ans.items(), key=lambda x:x[1], reverse=True):
    print(str(k))