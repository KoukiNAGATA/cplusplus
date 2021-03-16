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
#define inf 1000000000007
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;

int main() {
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll a, b, q, s_a, s_b, t_a, t_b, ans, x;
    ans = inf;
    cin >> a >> b >> q;
    vll s;
    vll t;
    REP(i, a){
        cin >> x;
        s.push_back(x);//shrine
    }
    REP(i, b){
        cin >> x;
        t.push_back(x);//temple
    }

    while(cin >> x){
        if(a > 1 && b > 1){
            //a > 1 && b > 1→考えるべきは8通り
            REP(i, a){
                if(i == a-1){
                    s_a = s[a-2];
                    s_b = s[a-1];
                }
                if(s[i] < x) {
                    continue;
                }else{//初めてスタートより東にshrine
                    if(i == 0){
                        s_a = s[0];
                        s_b = s[1];
                    }else{
                        s_b = s[i];
                        s_a = s[i-1];
                    }
                }
            }

            REP(i, b){
                if(i == b-1){
                    t_a = t[b-2];
                    t_b = t[b-1];
                }
                if(t[i] < x) {
                    continue;
                }else{//初めてスタートより東にtemple
                    if(i == 0){
                        t_a = t[0];
                        t_b = t[1];
                    }else{
                        t_b = t[i];
                        t_a = t[i-1];
                    }
                }
            }
            //まずshrineからいくパターン
            if(abs(s_a - x) + abs(t_a - s_a) < ans){
                ans = abs(s_a - x) + abs(t_a - s_a);
            }
            if(abs(s_b - x) + abs(t_a - s_b) < ans){
                ans = abs(s_b - x) + abs(t_a - s_b);
            }
            if(abs(s_a - x) + abs(t_b - s_a) < ans){
                ans = abs(s_a - x) + abs(t_b - s_a);
            }
            if(abs(s_b - x) + abs(t_b - s_b) < ans){
                ans = abs(s_b - x) + abs(t_b - s_b);
            }

            //次にtempleからいくパターン
            if(abs(t_a - x) + abs(s_a - t_a) < ans){
                ans = abs(t_a - x) + abs(s_a - t_a);
            }
            if(abs(t_b - x) + abs(s_a - t_b) < ans){
                ans = abs(t_b - x) + abs(s_a - t_b);
            }
            if(abs(t_a - x) + abs(s_b - t_a) < ans){
                ans = abs(t_a - x) + abs(s_b - t_a);
            }
            if(abs(t_b - x) + abs(s_b - t_b) < ans){
                ans = abs(t_b - x) + abs(s_b - t_b);
            }
        }else if(a == 1 && b > 1){
            //a == 1 && b > 1→考えるべきは4通り
            s_a = s[0];

            REP(i, b){
                if(i == b-1){
                    t_a = t[b-2];
                    t_b = t[b-1];
                }
                if(t[i] < x) {
                    continue;
                }else{//初めてスタートより東にtemple
                    if(i == 0){
                        t_a = t[0];
                        t_b = t[1];
                    }else{
                        t_b = t[i];
                        t_a = t[i-1];
                    }
                }
            }
            //まずshrineからいくパターン
            if(abs(s_a - x) + abs(t_a - s_a) < ans){
                ans = abs(s_a - x) + abs(t_a - s_a);
            }
            if(abs(s_a - x) + abs(t_b - s_a) < ans){
                ans = abs(s_a - x) + abs(t_b - s_a);
            }

            //次にtempleからいくパターン
            if(abs(t_a - x) + abs(s_a - t_a) < ans){
                ans = abs(t_a - x) + abs(s_a - t_a);
            }
            if(abs(t_b - x) + abs(s_a - t_b) < ans){
                ans = abs(t_b - x) + abs(s_a - t_b);
            }
        }else if(a > 1 && b == 1){
            //a > 1 && b == 1→考えるべきは4通り
            REP(i, a){
                if(i == a-1){
                    s_a = s[a-2];
                    s_b = s[a-1];
                }
                if(s[i] < x) {
                    continue;
                }else{//初めてスタートより東にshrine
                    if(i == 0){
                        s_a = s[0];
                        s_b = s[1];
                    }else{
                        s_b = s[i];
                        s_a = s[i-1];
                    }
                }
            }
            t_a = t[0];
            //まずshrineからいくパターン
            if(abs(s_a - x) + abs(t_a - s_a) < ans){
                ans = abs(s_a - x) + abs(t_a - s_a);
            }
            if(abs(s_b - x) + abs(t_a - s_b) < ans){
                ans = abs(s_b - x) + abs(t_a - s_b);
            }

            //次にtempleからいくパターン
            if(abs(t_a - x) + abs(s_a - t_a) < ans){
                ans = abs(t_a - x) + abs(s_a - t_a);
            }
            if(abs(t_a - x) + abs(s_b - t_a) < ans){
                ans = abs(t_a - x) + abs(s_b - t_a);
            }
        }else{
            //a = 1 && b == 1→考えるべきは2通り
            s_a = s[0];
            t_a = t[0];
            //まずshrineからいくパターン
            if(abs(s_a - x) + abs(t_a - s_a) < ans){
                ans = abs(s_a - x) + abs(t_a - s_a);
            }

            //次にtempleからいくパターン
            if(abs(t_a - x) + abs(s_a - t_a) < ans){
                ans = abs(t_a - x) + abs(s_a - t_a);
            }
        }
        cout << ans << endl;
    }
	return 0;
}