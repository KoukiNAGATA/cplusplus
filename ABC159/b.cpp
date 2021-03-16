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
    ll n, m;
    vector<char> s;
    char tmp;
    while(cin >> tmp){
        s.push_back(tmp);
    }
    n = s.size();
    //回文かどうか判定
    REP(i, (n-1)/2){
        if(s[i] != s[n-1-i]){
          cout << "No" << endl;
          return 0;
        }
    }

    //強い回文かどうか判定
    m = (n - 1)/2;
    REP(i, m-1){
        if(s[i] == s[m-1-i]) continue;
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
	return 0;
}