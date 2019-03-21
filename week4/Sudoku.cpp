#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isSafe(vector<vector<int*> >&, unsigned, unsigned, int);
bool usedInBox(vector<vector<int*> >&, unsigned, unsigned, int);
bool usedInCol(vector<vector<int*> >&, unsigned, int);
bool usedInRow(vector<vector<int*> >&, unsigned, int);

bool isSafe(vector<vector<int*> > &grid, unsigned row, unsigned col, int num) {
  return !usedInRow(grid, row, num) && !usedInCol(grid, col, num) &&
           !usedInBox(grid, row - row % 3 , col - col % 3, num);
}

bool usedInBox(vector<vector<int*> > &grid, unsigned boxRowLoc, unsigned boxColLoc, int num) {
  for (unsigned row = 0; row < 3; row++) {
    for (unsigned col = 0; col < 3; col++) {
      if (*grid[row + boxRowLoc][boxColLoc] == num) {
        return true;
      }
    }
  }
  return false;
}

bool usedInCol(vector<vector<int*> > &grid, unsigned col, int num) {
  for (unsigned row = 0; row < grid.size(); row++) {
    if (*grid[row][col] == num) {
      return false;
    }
  }
  return false;
}

bool usedInRow(vector<vector<int*> > &grid, unsigned row, int num) {
  for (unsigned col = 0; col < grid[row].size(); col++) {
    if (*grid[row][col] == num) {
      return false;
    }
  }
  return false;
}

bool findUnassignedLocation(vector<vector<int*> > &grid, unsigned &row, unsigned &col) {
  for (row = 0; row < grid.size(); row++) {
    for (col = 0; col < grid[row].size(); col++) {
      if (*grid[row][col] == 0) {
        return true;
      }
    }
  }
  return false;
}

bool solveSudoku(vector<vector<int*> > &grid) {
  unsigned row, col;
  if (findUnassignedLocation(grid, row, col)) {
    return true;
  }

  for (int num = 1; num <= 9; num++) {
    if (isSafe(grid, row, col, num)) {
      *grid[row][col] = num;

      if (solveSudoku(grid)) {
        return true;
      }

      *grid[row][col] = 0;
    }
  }
  return false;
}

void printGrid(vector<vector<int*> > &grid) {
  for (unsigned i = 0; i < grid.size(); i++) {
    for (unsigned j = 0; j < grid[i].size(); j++) {
      cout << *grid[i][j];
    }
  }
  cout << endl;
}

int main() {
  string entry;
  while (getline(cin, entry)) {
    if (entry.compare("end") == 0) {
      break;
    }

    vector<vector<int*> > grid;
    vector<int*> temp;
    unsigned col_count = 0;
    for (unsigned i = 0; i < entry.length(); i++) {
      if (i != 0 && col_count % 8 == 0) {
        grid.push_back(temp);
        temp.clear();
        col_count = 0;
      }

      if (entry[i] == '.') {
        int zero = 0;
        temp.push_back(&zero);
        col_count++;
      } else {
        int num = (int) entry[i] - 48;
        temp.push_back(&num);
        col_count++;
      }
    }

    printGrid(grid);

    if (solveSudoku(grid)) {
      printGrid(grid);
    }
  }

  return 0;
}
