#include <iostream>
#include <vector>
using namespace std;
#define inf 1000000007 // 評価値の仮の最大値

int n;
int m = 0;
int h = inf;
int h_next = inf;
vector<vector<int>> a;
vector<vector<int>> a_tmp;
vector<vector<int>> a_next;
vector<vector<int>> b;
vector<vector<int>> ans;

int eval(vector<vector<int>> a, vector<vector<int>> b){//評価値の計算
    int e = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] != b[i][j]) e++;
        }
    }
    return e;
}

vector<vector<int>> lotate(vector<vector<int>> a, int i, int j, int k){//回転操作
    vector<vector<int>> a_next = a;
    int tmp = 0;
    if(i == 1 && k == 1){//行、上
        tmp = a[0][j];
        for(int l = 0; l < n-1; l++){
            a[l][j] = a[l+1][j];
        }
        a[n-1][j] = tmp;
    }else if(i == 1 && k == 2){//行、下
        tmp = a[n-1][j];
        for(int l = 1; l < n; l++){
            a[l][j] = a[l-1][j];
        }
        a[0][j] = tmp;
    }else if(i == 2 && k == 1){//列、左
        tmp = a[j][0];
        for(int l = 0; l < n-1; l++){
            a[j][l] = a[j][l+1];
        }
        a[j][n-1] = tmp;
    }else{//列、右
        tmp = a[j][n-1];
        for(int l = 1; l < n; l++){
            a[j][l] = a[j][l-1];
        }
        a[j][0] = tmp;
    }

    return a_next;
}

int main() {
    cin >> n;
    int tmp;//入力を受け付ける変数
    //要素数をn*nに変更
    a.resize(n);
    b.resize(n);
    for(int i = 0; i < n; i++){
        a[i].resize(n);
        for(int j = 0; j < n; j++){
            cin >> tmp;
            a.at(i).at(j) = tmp;
        }
    }
    a_tmp = a;
    a_next = a;
    for(int i = 0; i < n; i++){
        b[i].resize(n);
        for(int j = 0; j < n; j++){
            cin >> tmp;
            b.at(i).at(j) = tmp;
        }
    }
    h = eval(a, b);

    //(n^2)!回を求める
    int residue = 1;
    for(int i = 1; i <= n*n; i++) residue *= i;//残りの最高試行回数
    //探索
    bool flg = 1;//変更があったか
    while(residue > m){
        if(h == 0){
            cout << "yes" <<"\n";
            cout << m <<"\n";
            for(int i = 0; i < ans.size(); i++){
                cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << "\n";
            }
            return 0;
        }
        a.resize(m+1);
        a[m].resize(3);

        //2*n*2通りを試す
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < 2; k++){
                    a_next = lotate(a, i, j, k);
                    h_next = eval(a_next, b);
                    if(h_next < h){//更新
                        flg = 0;
                        a_tmp = a_next;
                        ans.at(m).at(0) = i;
                        ans.at(m).at(1) = j;
                        ans.at(m).at(2) = k;
                    }
                }
            }
        }

        if(flg){//更新されなかった
            cout << "no" <<"\n";
            return 0;
        }
        m ++;
        flg = 1;
        a = a_tmp;
    }

    //上限まで操作を行った
    cout << "no" <<"\n";
	return 0;
}