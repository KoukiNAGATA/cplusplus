// 双方向連結リスト
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
using Graph = vector<vector<int>>;

// 連結リストの各ノードを表す構造体
struct Node {
    Node *prev, *next;
    string name; // ノードに付随している値
    Node(string name_ = "") : prev(NULL), next(NULL), name(name_) {}
};

// 番兵を表すノードをグローバル領域に置いておく
Node *nil;

// 初期化
void init(){
    nil = new Node();
    nil->prev = nil;
    nil->next = nil;
}

// リストを出力
void printList(){
    Node *cur = nil->next; // 先頭から出発
    for(; cur != nil; cur = cur->next){
        cout << cur->name << " -> ";
    }
    cout << endl;
}

// ノードpの直後にノードvを挿入する
void insert(Node *v, Node *p = nil){
    v->next = p->next;
    p->next->prev = v;
    p->next = v;
    v->prev = p;
}

// ノードvを削除する
void erase(Node *v){
    if (v == nil) return; // vが番兵の場合何もしない
    v->prev->next = v->next;
    v->next->prev = v->prev;
    delete v; // メモリを開放
}

int main(){
    init();

    vector<string> names = {"山本", "渡邊", "伊藤", "高橋"};

    // 連結リスト作成: 各ノードを生成して連結リストの先頭に挿入していく
    Node  *watanabe;
    for(int i = 0; i < (int)names.size(); ++i){
        // ノードを作成
        Node *node = new Node(names[i]);

        // 作成したノードを連結リストの先頭に挿入する
        insert(node);

        // watanabeノードを保持しておく
        if(names[i] == "渡邊") watanabe = node;
    }

    // watanabeノードを削除する
    cout << "before: ";
    printList();
    cout << "after: ";
    erase(watanabe);
    printList();
    return 0;
}