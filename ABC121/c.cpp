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

//昇順
bool lessPair(const P& l, const P& r){return l.first < r.first;}

int main(){
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    ll ans = 0;
    vector<P> drink(n);
    REP(i, n){
        ll a, b;
        cin >> drink[i].first >> drink[i].second;
    }
    sort(drink.begin(), drink.end(), lessPair);

    ll i = 0;
    while(m > 0){
        ll a = drink[i].first;
        ll b = drink[i].second;
        if(b > m){
            ans += a * m;
            break;
        }else{
            ans += a * b;
            m -= b;
            i ++;
        }
    }
    
    cout << ans << endl;
}