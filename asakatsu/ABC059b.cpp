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

int main() {
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    string a, b;
    cin >> a >> b;
    if(a.size() > b.size()){
        cout << "GREATER" <<"\n";
        return 0;
    }else if(a.size() < b.size()){
        cout << "LESS" <<"\n";
        return 0;
    }else{
        REP(i, a.size()){
            if(a[i] > b[i]){
                cout << "GREATER" <<"\n";
                return 0;
            }else if(a[i] < b[i]){
                cout << "LESS" <<"\n";
                return 0;
            }
        }
        
    }
    cout << "EQUAL" <<"\n";
	return 0;
}
