#include <iostream>
using namespace std;

char matrix[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

void drawBoard() {
    cout << " " << matrix[0][0] << " | " << matrix[0][1] << " | " << matrix[0][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << matrix[1][0] << " | " << matrix[1][1] << " | " << matrix[1][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << matrix[2][0] << " | " << matrix[2][1] << " | " << matrix[2][2] << endl;
};

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (matrix[i][0] == 'X' && matrix[i][1] == 'X' && matrix[i][2] == 'X') return true;
        if (matrix[0][i] == 'X' && matrix[1][i] == 'X' && matrix[2][i] == 'X') return true;
    }
    if (matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X') return true;
    if (matrix[0][2] == 'X' && matrix[1][1] == 'X' && matrix[2][0] == 'X') return true;

    for (int i = 0; i < 3; i++) {
        if (matrix[i][0] == 'O' && matrix[i][1] == 'O' && matrix[i][2] == 'O') return false;
        if (matrix[0][i] == 'O' && matrix[1][i] == 'O' && matrix[2][i] == 'O') return false;
    }
    if (matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O') return false;
    if (matrix[0][2] == 'O' && matrix[1][1] == 'O' && matrix[2][0] == 'O') return false;
    return false;
}

void Bot_logic() {
    short pos_x_random, pos_y_random;
    do {
        pos_x_random = rand() % 3; 
        pos_y_random = rand() % 3; 
    } while (matrix[pos_y_random][pos_x_random] != ' ');
    matrix[pos_y_random][pos_x_random] = 'O';
    drawBoard();
}

void Select_in_matrix(short x, short y) {
    matrix[y][x] = 'X';
    drawBoard();
    if (!checkWin()) {
        Bot_logic();
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    srand(time(NULL));
    unsigned short player_pos_x, player_pos_y;

    for (short i = 0; i < 9; i++) {
        cout << "Выбери позицию x, y для хода (0-2): ";
        cin >> player_pos_x >> player_pos_y;

        // Проверка на выход за пределы
        if (player_pos_x < 0 || player_pos_x > 2 || player_pos_y < 0 || player_pos_y > 2) {
            cout << "Позиция вне границ доски. Попробуйте снова." << endl;
            i--;
            continue;
        }

        if (matrix[player_pos_y][player_pos_x] != ' ') {
            cout << "Не ходи на занятую клетку." << endl;
            i--; 
        }
        else {
            Select_in_matrix(player_pos_x, player_pos_y);
            if (checkWin()) {
                cout << "Игрок победил!" << endl;
                break;
            }
            if (!checkWin()) {
                cout << "Бот победил!" << endl;
                break;
            }
        }
    }

    return 0;
}