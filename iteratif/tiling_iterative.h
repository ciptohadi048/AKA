#ifndef TILING_ITERATIVE_H
#define TILING_ITERATIVE_H

#include <vector>
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

// Fungsi untuk mencetak papan
void print_board(const vector<vector<int>>& board);

// Fungsi untuk menempatkan domino di papan
bool place_domino(vector<vector<int>>& board, int x, int y);

// Fungsi untuk menempatkan tromino di papan
bool place_tromino(vector<vector<int>>& board, int x, int y);

// Fungsi untuk mengisi papan dengan domino dan tromino
void tiling_iterative(int n);
void test_algorithm(int n);
bool is_filled(const vector<vector<int>>& board);
void remove_domino(vector<vector<int>>& board, int x, int y);
void remove_tromino(vector<vector<int>>& board, int x, int y) ;
bool solve(vector<vector<int>>& board, int n, int x, int y, int marker);
void tiling_backtracking(int n);

#endif // TILING_ITERATIVE_H
