#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    //cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, q, l, r;
    string s;

    cin >> n >> q >> s;
    //i番目までの文字列にいくつACが含まれるかを、整数の配列として保存する
    vector<int> data(n+1, 0);
    for(int i = 1; i < n; i++){
        if(s[i-1] == 'A' && s[i] == 'C'){
            data[i] += 1;
        }
        data[i] += data[i-1]; 
    }
    //n番目は次にCがないのでn-1番目と同じ
    data[n] += data[n-1]; 

    for(int i = 0; i < q; i++){
        //先に部分列の数を数えた配列を作った後で入力し、参照。そうすることでループを回す回数が1度で済む。
        cin >> l >> r;
        cout <<data[r-1] - data[l-1] << endl;
    }
    return 0;
}
