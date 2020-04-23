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
    int n, a, b;
    cin >> n;
    vector<vector<int>> g(n, vector<int>(n, 0));
    //無向グラフ作成
    FOR(i, 1, n){
        cin >> a >> b;
        g[a][b] = 1;
    }


    cout << ans << endl;
    return 0;
    
}