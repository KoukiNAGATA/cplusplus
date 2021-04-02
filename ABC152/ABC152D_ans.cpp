#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;

  vector<vector<int>> c(10, vector<int>(10, 0));

  for (int i = 1; i <= N; i++)
  { //1〜Nまでの全ての数について、1番上の数と下の数の組を作って、その組の数をストックしておく
    int last = i % 10;
    int tmp = i;
    while (tmp >= 10)
      tmp /= 10; //割り切れなくなるまで割れば1番上の桁が出るよね
    int top = tmp;

    c[top][last]++;
  }

  int ans = 0;
  for (int i = 1; i <= 9; i++)
  {
    for (int j = 1; j <= 9; j++)
    {
      ans += c[i][j] * c[j][i]; //初めがi終わりがjの組の個数 * 初めがj終わりがiの組の個数
    }
  }

  cout << ans << "\n";
}
