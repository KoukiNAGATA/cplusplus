#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int step;//命令の回数を保持する変数
    int board_value = 0;//現在の白板の値
    vector<int> pin_value;//保持している値の配列
    string instruction;//命令を受け付ける文字列の変数
    cin >> step;
    for(int i = 0; i < step; i++){//step回操作を行う
        cin >> instruction;
        if(instruction == "add"){
            board_value ++;
        }else if(instruction == "pin"){
            pin_value.push_back(board_value);
        }else if(instruction == "rollback"){//pinの末尾の値をboardに反映して、その値を削除する。
            board_value = pin_value.back();
            pin_value.pop_back();
        }else if(instruction == "print"){
            cout << board_value << endl;
        }
    }
	return 0;
}