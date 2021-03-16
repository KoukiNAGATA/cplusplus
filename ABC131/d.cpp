#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i <= n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n)
#define MAX 100000
#define inf 1000000007
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;

// 区間を終端時刻で大小比較する関数
bool cmp(const P &a, const P &b){
    return a.second < b.second;
}

int main() {
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<P> inter(n);
    REP(i, n) cin >> inter[i].first >> inter[i].second;
    sort(inter.begin(), inter.end(), cmp);
    ll current = 0;
    REP(i, n){
        if(current + inter[i].first <= inter[i].second){
            current += inter[i].first;
            continue; //今の仕事ができる
        }
        cout << "No" <<"\n";
        return 0;
    }
    cout << "Yes" <<"\n";
	return 0;
}