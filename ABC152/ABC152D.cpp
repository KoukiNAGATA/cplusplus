#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000007;

int main() {
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    int cnt = 0;
    int M, m, num;

	cin >> n;
    num = to_string(n).length();
    m = n % 10;//1番小さい桁
    for(int i = 1;i < num; i++){
        n /= 10;
    }
    M = n;//1番大きい桁

//0始まりはないので1から順に数えていく
    if(M <= m){
        for(int j = 1; j <= num; j++){//桁数
            for(int k = 1; k <= num; k++){//桁数
                if(j>2 && k > 2){
                    cnt += 10 * (j-2) * (k-2) * M * M;
                }else if(j > 2 && k == 2){//2桁*2桁は2種類あり得る
                    cnt += 10 * (j-2) * M * M;
                }else if(j == 2 && k == 2){//2桁*2桁は2種類あり得る
                    cnt += M * M;
                }else{//2桁*2桁未満は複数通り作れない
                    cnt ++ M;
                }
            }
        }
        if(M < 9){//最大桁を含まなくなる
            for(int i = M + 1; i <= 9; i++){
                for(int j = 1; j < num; j++){//桁数分
                    for(int k = 1; k < num; k++){//桁数分
                        if(j>2){
                            cnt += 10 * (j-2) * (k-2);
                        }else{//2桁以下は複数通り作れない
                            cnt ++;
                        }
                    }
                }
            }
        }
    }else{
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= num; j++){//桁数分
                for(int k = 1; k <= num; k++){//桁数分
                    if(j>2){
                        cnt += 10 * (j-2) * (k-2);
                    }else{//2桁以下は複数通り作れない
                        cnt ++;
                    }
                }
            }
        }
        if(m < 9){//最大桁を含まなくなる
            for(int i = m + 1; i <= 9; i++){
                for(int j = 1; j < num; j++){//桁数分
                    for(int k = 1; k < num; k++){//桁数分
                        if(j>2){
                            cnt += 10 * (j-2) * (k-2);
                        }else{//2桁以下は複数通り作れない
                            cnt ++;
                        }
                    }
                }
            }
        }
    }

    cout << cnt << endl;
	return 0;
}