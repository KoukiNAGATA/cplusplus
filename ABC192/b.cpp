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

    int n; 
    cin >> n;
    vector<pair<int, int>> a(n); 
    REP (i, n) cin >> a[i].first >> a[i].second;
    vector<pair<int, int>> b(n); 
    REP (i, n) cin >> b[i].first >> b[i].second;

    sort(begin(a), end(a));
    sort(begin(b), end(b));
    vector<int> by;
    int result = 0;
    while (not a.empty()) {
        int ax, ay; 
        tie(ax, ay) = a.back();
        a.pop_back();
        while (not b.empty() and ax < b.back().first) {
            by.push_back(b.back().second);
            b.pop_back();
        }
        int j = -1;
        REP (i, by.size()) if (ay < by[i]) {
            if (j == -1 or by[i] < by[j]) {
                j = i;
            }
        }
        if (j != -1) {
            by.erase(by.begin() + j);
            result += 1;
        }
    }

    cout << "Yes" <<"\n";
	return 0;
}