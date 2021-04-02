#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <algorithm>
#define REP(i, n) for (ll i = 0; i < n; i++)
#define REPR(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for (ll i = m; i <= n; i++)
#define FORR(i, m, n) for (ll i = m; i >= n; i--)
#define SORT(v, n) sort(v, v + n)
#define MAX 100000
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
using p = pair<int, int>;

int main()
{
  int k;
  cin >> k;
  vll a;
  for (int i = 1; i <= 9; ++i)
    a.push_back(i); //頭を格納
  while (1)
  { //無限ループ
    if (k <= a.size())
    { //k番目が存在するようになったら出力。プログラム終了。
      cout << a[k - 1] << "\n";
      return 0;
    }
    k -= a.size(); //これまでに列挙したルンルン数の数だけ引く。
    vector<ll> old;
    swap(old, a); //ルンルン数の初期化。
    for (ll x : old)
    { //配列のfor文
      for (int i = -1; i <= 1; ++i)
      {
        int d = x % 10 + i;
        if (d < 0 || d > 9)
          continue;         //桁上げ桁下げはルンルン数でない
        ll nx = x * 10 + d; //お尻につける
        a.push_back(nx);
      }
    }
  }
  return 0;
}
