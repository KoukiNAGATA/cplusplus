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

int main() {
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a, b;
    cin >> a >> b;
    if(a+b >= 15 && b >= 8){
        cout << 1 <<"\n";
        return 0;
    } else if(a+b >= 10 && b >= 3){
        cout << 2 <<"\n";
        return 0;
    } else if(a+b >= 3){
        cout << 3 <<"\n";
        return 0;
    }
    cout << 4 <<"\n";
	return 0;
}