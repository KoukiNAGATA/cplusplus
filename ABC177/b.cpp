#include <bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i <= n; i++)
#define FORR(i, m, n) for(ll i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n)
#define MAX 100000
#define inf 1000000007
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
using graph = vector<vector<int>>;

int main() {
    //cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s, t;
    ll ls, lt, m, tmp;
    m = 0;
    cin >> s >> t;
    ls = s.length();
    lt = t.length();
    
    FOR(i, 0, ls - lt){
        tmp = 0;
        REP(j, lt){
            if(s[i+j] == t[j]){
                tmp ++;
            }
        }
        m = max(m, tmp);
    }
    

    cout << lt - m <<"\n";
	return 0;
}