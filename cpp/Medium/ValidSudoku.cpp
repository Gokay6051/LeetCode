#include <vector>
#include <unordered_map>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        std::unordered_map<int, std::vector<char>> x;
        std::unordered_map<int, std::vector<char>> y;
        std::unordered_map<int, std::vector<char>> subgrid;

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                // Karakter '1' ile '9' aras�nda de�ilse ve '.' de�ilse devam et
                if (board[i][j] != '.' && (board[i][j] < '1' || board[i][j] > '9'))
                    return false;

                // E�er karakter '.', yani bo� ise, bu h�creyi atla
                if (board[i][j] == '.') continue;
                
                // E�er karakter x[i] ya da y[j] de daha �nce varsa, false d�nd�r
                if (isCharInVector(x[i], board[i][j]) || isCharInVector(y[j], board[i][j]) ||
                    isCharInVector(subgrid[3 * (i / 3) + j / 3], board[i][j]))
                    return false;

                // E�er daha �nce yoksa, x[i], y[j] ve subgrid vekt�rlerine karakteri ekle
                x[i].push_back(board[i][j]);
                y[j].push_back(board[i][j]);
                subgrid[3 * (i / 3) + j / 3].push_back(board[i][j]);
            }
        }
        return true;
    }

private:
    // Verilen vekt�rde belirli bir karakterin olup olmad���n� kontrol eden yard�mc� fonksiyon
    bool isCharInVector(const std::vector<char>& vec, char targetChar) {
        for (char c : vec) {
            if (c == targetChar) return true;
        }
        return false;
    }
};
