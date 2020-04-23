#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<utility>
#include<algorithm>
#include<queue>
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

int main() {

    string s;
    cin >> s;

    int n = s.length();
    vector<ll> a(n+1), b(n+1);
    REP(i, n){
        if(s[i] == '<'){
            a[i+1] = a[i] + 1;
        }
    }
    for(int i=n-1; i>=0; --i){
        if(s[i] == '>'){
            b[i] = b[i+1] + 1;
        }
    }

    ll ans = 0;
    REP(i, n+1){
        ans += max(a[i], b[i]);
    }
    cout << ans << endl;

    return 0;
}
