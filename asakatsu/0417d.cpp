#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<utility>
#include<algorithm>
#include<queue>
#include<cmath>
#include<iomanip>
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
    //cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, i;
    i = 0;
    cin >> n;
    vector<char> s;
    string ans = "";
    char tmp;
    while(cin >> tmp) s.push_back(tmp);

    while(1){
        ll left = 0; ll right = 0;
        REP(i, s.size()){
            s[i] == '('? left++ : right++;
            if(left<right) break;
        }
        if(left<right){//)が多い時点でアウトなので(を足しておく
                s.insert(s.begin(), '(');
        }else if(left>right){
            s.push_back(')');
        }else{
            break;
        }
    }
    REP(i, s.size()) ans = ans += s[i];
    cout << ans << endl;
	return 0;
}