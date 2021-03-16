#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
using P = pair<int, char>;

int main(){
// cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    char a, b;//aが呪文bが床・左右
    int ans = 0;
    vector<char> cha;
    vector<char> floor;
    vector<char> wiz;
    vector<pair<int, char>> p;

    REP(i, n){
//床の文字とゴーレムの初期化
        cin >> b;
        floor[i] = b;
        p.push_back(P(i, floor[i]));
    }

    REP(i, q){
//魔法を配列に入れる
        cin >> a >> b;
        wiz[i] = a;
        cha[i] = b;
    }

    REP(i, q){
        if(cha[i] == 'L'){
            REP(j, p.size()){
                if(wiz[i] == p[j].second){
                    p[j].first -= 1;
                    p[j].second = floor[p[j].first];
                }
                if(p[j].first == -1){
                    p.erase(p.begin() + j-1);
                }
            }
        }else{
            REP(j, p.size()){
                if(wiz[i] == p[j].second){
                    p[j].first += 1;
                    p[j].second = floor[p[j].first];
                }
                if(p[j].first == n){
                    p.erase(p.begin() + j-1);
                }
            }
        }
    }
    ans = p.size();
    cout << ans << endl;
    return 0;
}