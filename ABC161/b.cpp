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
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, m, tmp, sum, cnt;
    sum = 0;
    cnt = 0;
    cin >> n >> m;
    vll a(n, 0);
    vll b(n, 0);
    REP(i, n){
        cin >> tmp;
        a[i] = tmp;
        b[i] = tmp * 4 * m;
        sum += tmp;
    }
    REP(i, n){
        if(b[i] >= sum) cnt++;
    }
    if(cnt >= m){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    
	return 0;
}