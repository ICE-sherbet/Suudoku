
#include "Suudoku.h"

Suudoku::Suudoku(vector<vector<int>>& arr, int x, int y)
{
    isClear = solve_sudoku(arr, x, y);
}

Suudoku::~Suudoku()
{
}

bool Suudoku::solve_sudoku(vector<vector<int>>& arr, int x, int y)
{
    if (y > 8) {
        return true;
    }
    else if (x > 8) {
        return solve_sudoku(arr, 0, y + 1);
    }
    else if (arr[y][x] != 0) {
        return solve_sudoku(arr, x + 1, y);
    }
    else {
        for (int i = 1; i < 10; i++) {
            int tmp = change_num(arr, x, y, i);
            if (tmp != 0) {
                if (solve_sudoku(arr, x + 1, y)) {
                    return true;
                }
            }
        }
        arr[y][x] = 0;
    }
    return false;
}
int Suudoku::change_num(vector<vector<int>>& arr, int x, int y, int n)
{
    if (check_vertically(arr, x, n) && check_horizontally(arr, y, n) && check_mass(arr, x, y, n)) {
        return arr[y][x] = n;
    }
    else {
        return 0;
    }
}
bool Suudoku::check_vertically(vector<vector<int>>& arr, int x, int n)
{
    for (int i = 0; i < 9; i++) {
        if (arr[i][x] == n) {
            return false;
        }
    }
    return true;
}
bool Suudoku::check_horizontally(vector<vector<int>>& arr, int y, int n)
{
    for (int i = 0; i < 9; i++) {
        if (arr[y][i] == n) {
            return false;
        }
    }
    return true;
}
bool Suudoku::check_mass(vector<vector<int>>& arr, int x, int y, int n)
{
    int _x = (x / 3) * 3;
    int _y = (y / 3) * 3;
    for (int i = _x; i < _x + 3; i++) {
        for (int j = _y; j < _y + 3; j++) {
            if (arr[j][i] == n) {
                return false;
            }
        }
    }
    return true;
}

bool Suudoku::getResult() {
    return isClear;
}