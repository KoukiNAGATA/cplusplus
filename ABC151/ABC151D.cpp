#include <bits/stdc++.h>
using namespace std;

int maze_count(int i, int j, vector<vector<bool>> done, vector<vector<char>> maze, int tmp){
    bool flag = false;
    if(i > 0 && i < 20){
        if(done.at(i-1).at(j) == false && maze.at(i-1).at(j) == '.'){
            done.at(i-1).at(j) == true;
            flag = true;
            tmp = maze_count(i-1, j, done, maze, tmp);
        }
        if(done.at(i+1).at(j) == false && maze.at(i+1).at(j) == '.'){
            done.at(i+1).at(j) == true;
            flag = true;
            tmp = std::max(tmp, maze_count(i+1, j, done, maze, tmp));
        }
    }
    if(j > 0 && j < 20){
        if(done.at(i).at(j-1) == false && maze.at(i).at(j-1) == '.'){
            done.at(i).at(j-1) == true;
            flag = true;
            tmp = std::max(tmp, maze_count(i, j-1, done, maze, tmp));
        }
        if(done.at(i).at(j+1) == false && maze.at(i).at(j+1) == '.'){
            done.at(i).at(j+1) == true;
            flag = true;
            tmp = std::max(tmp, maze_count(i, j+1, done, maze, tmp));
        }
    }
    if(flag == true){
        tmp++;
    }
    return tmp;
}

int main() {
    int h, w;
  	int max;

	cin >> h >> w;
    vector<vector<char>> maze(h, vector<char>(w));//迷路の配列

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> maze.at(i).at(j);
        }
    }

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            //スタートの基準は(i, j)
            int tmp = 0;//今回の手数を数える
            vector<vector<bool>> done(h, vector<bool>(w));//そこを通ったかの配列

            tmp = maze_count(i, j, done, maze, tmp);

            if(tmp >= max){
                max = tmp;
            }
        }
    }

    cout << max << endl;
	return 0;
}