#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;
#define MAX 100000

int main()
{
    std::string S;
    int a, b, M;
    a, b = 0;
    cin >> S;
    M = (int)(S.length());
    vector<string> L(M);
    for (int i = 0; i < M; i++)
    {
        L[i] = S.substr(i, 1);
        if (L[i] == "0")
        {
            a++;
        }
        else
        {
            b++;
        }
    }
    if (a > b)
    {
        cout << b * 2 << "\n";
        return 0;
    }
    else
    {
        cout << a * 2 << "\n";
        return 0;
    }
}