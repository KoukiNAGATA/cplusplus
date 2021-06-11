#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i <= n; i++)
#define FORR(i, m, n) for (int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v + n)
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;
using Edge = pair<int, ll>;
const ll INF = 1LL << 60;
const int MAX = 200000;
const int MOD = 1000000007;

// マージソート
void MergeSort(vector<int> &a, int l, int r)
{
    if (r - l == 1)
        return;
    int mid = l + (r - l) / 2;

    // 左半分のsort
    MergeSort(a, l, mid);
    // 右半分のsort
    MergeSort(a, mid, r);

    // 左と右の結果をコピー
    vector<int> buf;
    FOR(i, l, mid - 1)
    buf.push_back(a[i]);
    FORR(i, r - 1, mid)
    buf.push_back(a[i]);

    // Merge
    int index_l = 0, index_r = buf.size() - 1;
    FOR(i, l, r - 1)
    {
        if (buf[index_l] <= buf[index_r])
            a[i] = buf[index_l++]; // 左側採用
        else
            a[i] = buf[index_r--]; // 右側採用
    }
}
int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    // input;
    int n;
    cin >> n;
    vector<int> a(n);
    REP(i, n)
    cin >> a[i];

    // sort
    MergeSort(a, 0, n);

    // output
    REP(i, n)
    cout << a[i] << " ";
    cout << "\n";
    return 0;
}