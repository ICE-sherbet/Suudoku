#pragma once
#include <vector>

using namespace std;
class Suudoku
{
public:
	Suudoku(vector<vector<int>>& arr, int x, int y);
	~Suudoku();

	int change_num(vector<vector<int>>& arr, int x, int y, int n);
	bool check_vertically(vector<vector<int>>& arr, int x, int n);
	bool check_horizontally(vector<vector<int>>& arr, int y, int n);
	bool check_mass(vector<vector<int>>& arr, int x, int y, int n);
	bool solve_sudoku(vector<vector<int>>& arr, int x, int y);
	bool getResult();

private:
	bool isClear = false;

};
