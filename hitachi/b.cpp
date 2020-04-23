#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<utility>
#include<algorithm>
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
using p = pair<int, int>;

int main() {
    //cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    int A, B, M, x, y, tmp, ans, amin, bmin;
    cin >> A >> B >> M;
    ans = inf;
    amin = MAX;
    bmin = MAX;
    vector<int> a(A);
    vector<int> b(B);
    REP(i, A){
        cin >> tmp;
        a[i] = tmp;
        amin = min(amin, tmp);
    }
    REP(j, B){
        cin >> tmp;
        b[j] = tmp;
        bmin = min(bmin, tmp);
    }
    REP(k, M){
        cin >> x >> y >> tmp;
        ans = min(ans, a[x-1] + b[y-1] - tmp);//0オリジン
    }

    ans = min(ans, amin + bmin);
    cout << ans << endl;
    return 0;
    
}