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
    ll ac, wa, tle, re, n;
    ac = 0;
    wa = 0;
    tle = 0;
    re = 0;
    string tmp;
    cin >> n;
    REP(i, n){
        cin >> tmp;
        if(tmp == "AC"){
            ac ++;
        }else if(tmp == "WA"){
            wa ++;
        }
        else if(tmp == "TLE"){
            tle ++;
        }
        else if(tmp == "RE"){
            re ++;
        }
    }

    cout << "AC x "  << ac <<"\n";
    cout << "WA x "  << wa <<"\n";
    cout << "TLE x "  << tle <<"\n";
    cout << "RE x "  << re <<"\n";
	return 0;
}