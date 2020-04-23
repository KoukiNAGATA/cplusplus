#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
#include <sstream>
using namespace std;
#define MAX 100000

int main() {
    //cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);

	string S;
    int a, b, M;
    //ちゃんとそれぞれ初期化
    a = 0;
    b = 0;
    cin >> S;
    char c;
    M = (int)(S.length());
//charは1文字ずつ処理する。""で囲むと配列を表す。
    for(int i = 0; i < M; i++){
        //010101...にするチーム
        if(i % 2 ==0 && S[i] == '1'){
            a++;
        }else if(i % 2 ==1 && S[i] == '0'){
            a++;
        }//101010...にするチーム
        else if(i % 2 ==0 && S[i] == '0'){
            b++;
        }else if(i % 2 ==1 && S[i] == '1'){
            b++;
        }
    }

    if(a>b){
        cout << b << endl;
        return 0;
    }else{
        cout << a << endl;
        return 0;
    }
}