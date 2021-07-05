// Suudoku.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <vector>
#include "Suudoku.h"

using namespace std;
int main()
{
    std::cout << "Hello World!\nPlease Input Data!\n";
    vector<vector<int>> arr;
    arr.resize(9);
    for (int i = 0; i < 9; i++) {
        char* buf = new char[10];
        cin >> buf;
        for (int j = 0; j < 9; j++) {
            arr[i].push_back(int(buf[j]) - 48);
        }
        delete[]buf;
    }
    Suudoku suudoku = Suudoku(arr, 0, 0);
    string result = "解けなかった(´・ω・`)";
    if (suudoku.getResult()) {
        cout << "-------------------" << endl;
        for (int i = 0; i < 9; i++) {
            cout << '|';
            for (int j = 0; j < 8; j++) {
                cout << arr[i][j] << '|';
            }
            cout << arr[i][8];
            cout << '|' << endl;
            cout << "-------------------" << endl;
        }
        result = "解けた(　＾ω＾)";
    }

    cout << result << endl;
}