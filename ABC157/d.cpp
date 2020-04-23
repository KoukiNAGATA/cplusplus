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

struct UnionFind {
    vector<int> par;
    UnionFind(int n) : par(n, -1) {}//連結成分サイズの配列。最初はみんな根。

    //木の根を求める
    int root(int x){
        if(par[x] < 0){
            return x;//根
        }else{
            return root(par[x]);//経路圧縮(O(logn)になる)
        }
    }

    //xとyの属する集合を併合。小さい方をくっつける。
    void unite(int x, int y){
        //先に経路圧縮。根どうしを結合する。
        x = root(x);
        y = root(y);
        if(x == y) return ;
        if(par[x] > par[y]){//xの方が小さくする(連結成分サイズで見るとxの方が大きい)
            swap(x, y);
        }
        par[x] += par[y];//根となるxのサイズを大きくする。
        par[y] = x;//yの根はxに。葉はrootの値が正になる。
        return ;
    }

    //xとyが同じ集合に属するか判定
    bool same(int x, int y){ return root(x) == root(y);}

    //集合のサイズを返す
    int size(int x) { return -par[root(x)];}
};

int main() {
    //cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m, k, a, b;

    cin >> n >> m >> k;
    UnionFind uf(n+1);
    vector<int> FoB(MAX, 0);//人1〜nの友達またはブロックの関係にある人の数=あとで引く数
    

    REP(i, m){//友達関係、union-findを作る
        cin >> a >> b;
        FoB[a] += 1;
        FoB[b] += 1;
        uf.unite(a, b);
    }

    REP(i, k){//友達候補ならばブロック関係をFoBに加える。友達とブロックの関係はunion-find除けば同じ。
        cin >> a >> b;
        if(uf.same(a, b)){
            FoB[a] += 1;
            FoB[b] += 1;
        }
    }

    FOR(i, 1, n){//人iの友達候補の人数を出力
        cout << uf.size(i)-FoB[i]-1;//素集合から友達、ブロック、自分の分を引く
        if(i < n){
            cout << " ";
        }
    }
	return 0;
}