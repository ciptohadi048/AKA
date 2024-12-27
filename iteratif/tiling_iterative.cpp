#include "tiling_iterative.h"

void print_board(const vector<vector<int>>& board) {
    // Print papan secara bertahap setelah selesai
    for (const auto& row : board) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

bool is_filled(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int cell : row) {
            if (cell == 0) return false; // Ada sel kosong
        }
    }
    return true;
}

bool place_domino(vector<vector<int>>& board, int x, int y) {
    if (y + 1 < board.size() && board[x][y] == 0 && board[x][y + 1] == 0) {
        board[x][y] = 1;      // Bagian pertama domino
        board[x][y + 1] = 1;  // Bagian kedua domino
        return true;
    }
    return false;
}

void remove_domino(vector<vector<int>>& board, int x, int y) {
    board[x][y] = 0;
    board[x][y + 1] = 0;
}

bool place_tromino(vector<vector<int>>& board, int x, int y) {
    // Tromino berbentuk L ke bawah
    if (x + 1 < board.size() && y + 1 < board.size() &&
        board[x][y] == 0 && board[x + 1][y] == 0 && board[x][y + 1] == 0) {
        board[x][y] = 1;        // Bagian pertama tromino
        board[x + 1][y] = 1;    // Bagian kedua tromino
        board[x][y + 1] = 1;    // Bagian ketiga tromino
        return true;
    }
    return false;
}

void remove_tromino(vector<vector<int>>& board, int x, int y) {
    board[x][y] = 0;
    board[x + 1][y] = 0;
    board[x][y + 1] = 0;
}

bool solve(vector<vector<int>>& board, int n, int x, int y) {
    if (is_filled(board)) return true; // Jika papan penuh, solusi ditemukan

    for (int i = x; i < n; i++) {
        for (int j = (i == x ? y : 0); j < n; j++) {
            if (board[i][j] == 0) { // Jika sel kosong
                // Coba tempatkan tromino
                if (place_tromino(board, i, j)) {
                    if (solve(board, n, i, j)) return true;
                    remove_tromino(board, i, j); // Backtrack
                }
                // Coba tempatkan domino
                if (place_domino(board, i, j)) {
                    if (solve(board, n, i, j)) return true;
                    remove_domino(board, i, j); // Backtrack
                }
                return false; // Tidak bisa menempatkan ubin
            }
        }
    }
    return false; // Tidak ada solusi
}

void tiling_backtracking(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    if (solve(board, n, 0, 0)) {
        print_board(board); // Print papan setelah solusi ditemukan
    } else {
        cout << "Tidak ada solusi." << endl;
    }
}

void test_algorithm(int n) {
    auto start = chrono::high_resolution_clock::now();
    tiling_backtracking(n);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    cout << "Ukuran papan: " << n << endl;
    cout << "Waktu eksekusi: " << duration.count() << " detik." << endl;
}
