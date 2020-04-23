#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

//pairの第2引数でソート
typedef std::pair<int,int> ipair;
//昇順
bool lessPair(const ipair& l, const ipair& r){return l.second < r.second;}
//降順
bool greaterPair(const ipair& l, const ipair& r){return l.second > r.second;}


int main() {
    //cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);

	int N, tmp;
    cin >> N;
    //ちゃんと初期化する
    //pairの配列
    vector<ipair> vect2;
    int order = 1;

    for(int i = 0; i < N; i++){
		cin >> tmp;
        vect2.push_back(ipair(order, tmp));
        order++;
	}
    //第2引数でソート
    sort(vect2.begin(), vect2.end(), lessPair);

    for(int i = 0; i < N; i++){
		cout << vect2[i].first << " " << flush;
	}
    return 0;
}