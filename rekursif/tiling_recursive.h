#ifndef TILING_RECURSIVE_H
#define TILING_RECURSIVE_H

#include <vector>
#include <iostream>
#include <chrono>
using namespace std;

// Fungsi untuk mencetak papan
void print_board(const vector<vector<int>>& board);

// Fungsi untuk menempatkan domino secara rekursif
bool place_domino(vector<vector<int>>& board, int x, int y);

// Fungsi untuk menempatkan tromino secara rekursif
bool place_tromino(vector<vector<int>>& board, int x, int y);

// Fungsi untuk menyelesaikan tiling secara rekursif
bool tiling_recursive(vector<vector<int>>& board, int n);

// Fungsi untuk memulai tiling
void tiling(int n);
void test_algorithms(int n);

#endif // TILING_RECURSIVE_H
