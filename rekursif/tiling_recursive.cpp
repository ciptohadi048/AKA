#include "tiling_recursive.h"
void test_algorithms(int n) {
    // Uji algoritma rekursif
    auto start_recursive = std::chrono::high_resolution_clock::now();
    tiling(n); // Panggil fungsi tiling rekursif
    auto end_recursive = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_recursive = end_recursive - start_recursive;
     std::cout << "Ukuran papan: " << n << std::endl;
    std::cout << "Waktu eksekusi rekursif: " << duration_recursive.count() << " detik." << std::endl;
}
void print_board(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
        cout << "------------------" << endl; // Pembatas untuk setiap progres
}

bool place_domino(vector<vector<int>>& board, int x, int y) {
    // Cek apakah kita bisa menempatkan domino horizontal
    if (y + 1 < board.size() && board[x][y] == 0 && board[x][y + 1] == 0) {
        board[x][y] = 1;      // Menempatkan bagian pertama domino
        board[x][y + 1] = 1;  // Menempatkan bagian kedua domino
        return true;
    }
    // Cek apakah kita bisa menempatkan domino vertikal
    if (x + 1 < board.size() && board[x][y] == 0 && board[x + 1][y] == 0) {
        board[x][y] = 1;      // Menempatkan bagian pertama domino
        board[x + 1][y] = 1;  // Menempatkan bagian kedua domino
        return true;
    }
    return false;
}

bool place_tromino(vector<vector<int>>& board, int x, int y) {
    // Cek orientasi L ke bawah
    if (x + 1 < board.size() && y + 1 < board.size() &&
        board[x][y] == 0 && board[x + 1][y] == 0 && board[x][y + 1] == 0) {
        board[x][y] = 1;        // Menempatkan bagian pertama tromino
        board[x + 1][y] = 1;    // Menempatkan bagian kedua tromino
        board[x][y + 1] = 1;    // Menempatkan bagian ketiga tromino
        return true;
    }
    // Cek orientasi L ke atas
    if (x - 1 >= 0 && y + 1 < board.size() &&
        board[x][y] == 0 && board[x - 1][y] == 0 && board[x][y + 1] == 0) {
        board[x][y] = 1;        // Menempatkan bagian pertama tromino
        board[x - 1][y] = 1;    // Menempatkan bagian kedua tromino
        board[x][y + 1] = 1;    // Menempatkan bagian ketiga tromino
        return true;
    }
    return false;
}

bool tiling_recursive(vector<vector<int>>& board, int n) {
    // Basis kasus: jika semua sel terisi
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == 0) { // Temukan sel kosong
                // Coba tempatkan domino
                if (place_domino(board, i, j)) {
                    if (tiling_recursive(board, n)) {
                        return true; // Jika berhasil, kembalikan true
                    }
                    // Backtrack: hapus domino
                    board[i][j] = 0;
                    board[i][j + 1] = 0;
                }
                // Coba tempatkan tromino
                if (place_tromino(board, i, j)) {
                    if (tiling_recursive(board, n)) {
                        return true; // Jika berhasil, kembalikan true
                    }
                    // Backtrack: hapus tromino
                    board[i][j] = 0;
                    board[i + 1][j] = 0;
                    board[i][j + 1] = 0;
                }
                return false; // Jika tidak ada penempatan yang berhasil
            }
        }
    }
    return true; // Semua sel terisi
}

void tiling(int n) {
     vector<vector<int>> board(n, vector<int>(n, 0)); // Inisialisasi papan
    auto start = chrono::high_resolution_clock::now(); // Mulai pengukuran waktu
    if (tiling_recursive(board, n)) {
        auto end = chrono::high_resolution_clock::now(); // Akhiri pengukuran waktu
        chrono::duration<double> elapsed = end - start; // Hitung durasi
        print_board(board); // Cetak papan jika berhasil
    } else {
        cout << "Tidak ada solusi yang ditemukan." << endl;
    }
}
