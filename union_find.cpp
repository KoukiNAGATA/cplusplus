#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i <= n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n)
#define MAX 100000
#define inf 1000000007
#define mod 1000000007
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
using graph = vector<vector<int>>;

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