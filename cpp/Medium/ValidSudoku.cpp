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
                // Karakter '1' ile '9' arasýnda deðilse ve '.' deðilse devam et
                if (board[i][j] != '.' && (board[i][j] < '1' || board[i][j] > '9'))
                    return false;

                // Eðer karakter '.', yani boþ ise, bu hücreyi atla
                if (board[i][j] == '.') continue;
                
                // Eðer karakter x[i] ya da y[j] de daha önce varsa, false döndür
                if (isCharInVector(x[i], board[i][j]) || isCharInVector(y[j], board[i][j]) ||
                    isCharInVector(subgrid[3 * (i / 3) + j / 3], board[i][j]))
                    return false;

                // Eðer daha önce yoksa, x[i], y[j] ve subgrid vektörlerine karakteri ekle
                x[i].push_back(board[i][j]);
                y[j].push_back(board[i][j]);
                subgrid[3 * (i / 3) + j / 3].push_back(board[i][j]);
            }
        }
        return true;
    }

private:
    // Verilen vektörde belirli bir karakterin olup olmadýðýný kontrol eden yardýmcý fonksiyon
    bool isCharInVector(const std::vector<char>& vec, char targetChar) {
        for (char c : vec) {
            if (c == targetChar) return true;
        }
        return false;
    }
};
