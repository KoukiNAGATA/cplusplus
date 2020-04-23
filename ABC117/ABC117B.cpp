#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;


int main() {
	int N;
    cin >> N;
    //ちゃんと初期化する
    int s = 0;
	vector<int> L(N, 0);
	for(int i = 0; i < N; i++){
		cin >> L[i];
        s += L[i];
	}

    int m = *std::max_element(L.begin(), L.end());
        s -= m;
        if(s > m){
            cout << "Yes" << endl;
            return 0;
        }else{
            cout << "No" << endl;
            return 0;
        }
}