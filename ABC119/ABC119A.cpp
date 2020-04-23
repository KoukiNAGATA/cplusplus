#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    std::string S;
    cin >> S;
    S.erase(std::find(S.begin(), S.end(), '/'));
    S.erase(std::find(S.begin(), S.end(), '/'));
    int date = std::stoi(S);
    if(date <= 20190430){
        cout << "Heisei" << endl;
        return 0;
    }else{
        cout << "TBD" << endl;
        return 0;
    }
}