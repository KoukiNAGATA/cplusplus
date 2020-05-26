#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    //入力
    int n, m;
    vector<vector<char>> room(n+1, vector<char>(m+1));//マスの配列
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= m; j++){
        cin >> room.at(i).at(j);
      }
    }

    int I = 1;
    int J = 1;
    while(1){
        if(room.at(I).at(J) == 'N'){//1マス上に行ける場合は上へ
            room.at(I).at(J) == '#';
            if(I == 1) break;
        }else if(room.at(I).at(J) == 'S'){//1マス下に行ける場合は下へ
            room.at(I).at(J) == '#';
            if(I == n) break;
        }else if(room.at(I).at(J) == 'W'){//1マス左に行ける場合は左へ
            room.at(I).at(J) == '#';
            if(J == 1) break;
        }else if(room.at(I).at(J) == 'E'){//1マス右に行ける場合は右へ
            room.at(I).at(J) == '#';
            if(J == m) break;
        }else{
            break;
        }
    }

    //通過したマスの数を数える。
    int ans = 0;//答えのマスの数
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= m; j++){
        if(room.at(i).at(j) == '#') ans++;
      }
    }

    cout << ans <<"\n";
	return 0;
}