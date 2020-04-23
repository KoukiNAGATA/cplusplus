#include<iostream>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<algorithm>
using namespace std;
#define MAX 20000000000


int main() {
	int N, M;
    long cnt = 0;
    long money = 0;
    cin >> N >> M;
    //ちゃんと初期化する
    vector<long> A(N,0);
    vector<long> B(N,0);
    for(int i=0; i<N ; i++){
        cin >> A[i] >> B[i];
    }
    while(true){
        //これを何度もやると遅い
        std::vector<long>::iterator tmp = std::min_element(A.begin(), A.end());
        //その中で最小値のインデックスを返す
        int index = std::distance(A.begin(), tmp);
        if(B[index]<= M-cnt){
            cnt += B[index];
            money += A[index]*B[index];
            //その中で最小値を取り出す
            A.erase(A.begin()+index);
            B.erase(B.begin()+index);
        }else{
            money += A[index]*(M-cnt);
            cout << money << endl;
            return 0;
        }
    }
}
