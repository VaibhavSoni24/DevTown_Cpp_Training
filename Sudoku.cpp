#include <iostream>
using namespace std;

int puzzle[9][9] = 
{
  {3, 0, 0, 0, 2, 0, 0, 7, 0},
  {9, 0, 0, 5, 0, 0, 0, 1, 4},
  {0, 1, 6, 3, 7, 0, 0, 0, 8},
  {2, 0, 0, 8, 0, 0, 0, 0, 1},
  {5, 0, 0, 0, 4, 1, 8, 0, 0},
  {0, 8, 9, 0, 0, 0, 0, 5, 0},
  {0, 0, 5, 0, 1, 0, 2, 8, 0},
  {0, 4, 0, 0, 0, 6, 0, 9, 3},
  {7, 3, 1, 0, 8, 2, 0, 0, 0},
};

void print_puzzle(int puzzle[9][9]);
bool valid_move(int puzzle[9][9], int row, int col, int val);
bool solve_puzzle(int puzzle[9][9], int row, int col);

int main() 
{
  cout << "\n\tWelcome to SUDOKU Solver !!!" << endl;
  cout << "\nOriginal Puzzle:" << endl;
  print_puzzle(puzzle);
  
  if (solve_puzzle(puzzle, 0, 0)) 
  {
    cout << "\nThe puzzle is solved:" << endl;
    print_puzzle(puzzle);
  } 
  else 
  {
    cout << "\nThis puzzle is not solvable" << endl;
  }

  return 0;
}

bool solve_puzzle(int puzzle[9][9], int row, int col) 
{
  if (col == 9) 
  {
    if (row == 8) 
    {
      return true;
    }
    row++;
    col = 0;
  }

  if (puzzle[row][col] > 0)
  {
    return solve_puzzle(puzzle, row, col + 1);
  }

  for (int i = 1; i <= 9; i++) 
  {
    if (valid_move(puzzle, row, col, i)) 
    {
      puzzle[row][col] = i;
      if (solve_puzzle(puzzle, row, col + 1)) 
      {
        return true;
      }
      puzzle[row][col] = 0;
    }
  }

  return false;
}

bool valid_move(int puzzle[9][9], int row, int col, int val) 
{
  for (int i = 0; i < 9; i++) 
  {
    if (puzzle[row][i] == val) 
    {
      return false;
    }
  }

  for (int i = 0; i < 9; i++) 
  {
    if (puzzle[i][col] == val) 
    {
      return false;
    }
  }

  int r = row - row % 3;
  int c = col - col % 3;
  for (int i = 0; i < 3; i++) 
  {
    for (int j = 0; j < 3; j++) 
    {
      if (puzzle[r + i][c + j] == val) 
      {
        return false;
      }
    }
  }

  return true;
}

void print_puzzle(int puzzle[9][9]) 
{
  cout << "\n+-------+-------+-------+" << endl;
  for (int row = 0; row < 9; row++) 
  {
    if (row % 3 == 0 && row != 0) 
    {
      cout << "|-------+-------+-------|" << endl;
    }
    for (int col = 0; col < 9; col++) 
    {
      if (col % 3 == 0) 
      {
        cout << "| ";
      }
      if (puzzle[row][col] != 0) 
      {
        cout << puzzle[row][col] << " ";
      } 
      else 
      {
        cout << "  ";
      }
    }
    cout << "|" << endl;
  }
  cout << "+-------+-------+-------+" << endl;
}