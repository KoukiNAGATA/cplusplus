#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


void move(int I, int J, vector<vector<char>> maze, int n, int m){//その時点のマスにおける操作を決める
    if(maze.at(I).at(J) == 'N'){//1マス上に行ける場合は上へ
        maze.at(I).at(J) = '#';
        if(I == 1) return;
        move(I-1, J, maze, n, m);
    }else if(maze.at(I).at(J) == 'S'){//1マス下に行ける場合は下へ
        maze.at(I).at(J) = '#';
        if(I == n) return;
        move(I+1, J, maze, n, m);
    }else if(maze.at(I).at(J) == 'W'){//1マス左に行ける場合は左へ
        maze.at(I).at(J) = '#';
        if(J == 1) return;
        move(I, J-1, maze, n, m);
    }else if(maze.at(I).at(J) == 'E'){//1マス右に行ける場合は右へ
        maze.at(I).at(J) = '#';
        if(J == m) return;
        move(I, J+1, maze, n, m);
    }

    //マスが通過済み(#)
    return;
}

int main() {
  //入力
  int n, m;
	cin >> n >> m;
  vector<vector<char>> maze(n, vector<char>(m));//迷路の配列

    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        cin >> maze.at(i).at(j);
      }
    }

  move(1, 1, maze, n, m);//(1, 1)から移動を開始する。

  //通過したマスの数を数える。
  int ans = 0;//答えのマスの数
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(maze.at(i).at(j) == '#') ans++;
    }
  }

  cout << ans <<"\n";
	return 0;
}