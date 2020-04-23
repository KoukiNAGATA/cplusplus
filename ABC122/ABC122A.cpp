#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    //cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string b;
    cin >> b;
    if(b == "A"){
        cout << "T" << endl;
        return 0;
    }else if(b == "T"){
        cout << "A" << endl;
        return 0;
    }else if(b == "G"){
        cout << "C" << endl;
        return 0;
    }else if(b == "C"){
        cout << "G" << endl;
        return 0;
    }
}