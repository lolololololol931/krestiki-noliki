#include <iostream>
#define r "\033[31m"
#define y "\033[33m"
#define o "\033[0m"

using namespace std;


char board[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

class BoardDraw {
public:
    void DrawBoard() {
        cout << "\n";
        for (int i = 0; i < 9; i++) {
            if (board[i] == 'X')
                cout << " " << r << board[i] << o;
            else if (board[i] == 'O')
                cout << " " << y << board[i] << o;
            else
                cout << " " << board[i];

            if ((i + 1) % 3 == 0)
                cout << " \n";
            else
                cout << " |";
        }
        cout << "---|---|---\n";
        cout << "\n";
    }
};

class Check {
public:
    bool CheckWin(char player) {
        for (int i = 0; i < 3; i++) {
            if (board[i * 3] == player && board[i * 3 + 1] == player && board[i * 3 + 2] == player) return true;
            if (board[i] == player && board[i + 3] == player && board[i + 6] == player) return true;
        }
        if (board[0] == player && board[4] == player && board[8] == player) return true;
        if (board[2] == player && board[4] == player && board[6] == player) return true;
        return false;
    }

};

class Draw {
public:
    bool IsDraw() {
        for (int i = 0; i < 9; i++) {
            if (board[i] != 'X' && board[i] != 'O') return false;
        }
        return true;
    }
};

int GetMove() {
    int move;
    cout << "номер клітинки: ";
    cin >> move;
    while (move < 1 || move > 9 || board[move - 1] == 'X' || board[move - 1] == 'O') {
        cout << "помилка ";
        cin >> move;
    }
    return move - 1;
}

void BotMove() {
    int move;
    do {
        move = rand() % 9;
    } while (board[move] == 'X' || board[move] == 'O');
    board[move] = 'O';
}

int main() {
    system("chcp 1251>nul");
    srand(time(0));
    BoardDraw b1;
    Check c1;
    Draw d1;
    b1.DrawBoard();
    for (int i = 0; i < 9; i++) {
        if (i % 2 == 0) {
            int move = GetMove();
            board[move] = 'X';
        }
        else {
            BotMove();
        }
        b1.DrawBoard();
        if (c1.CheckWin('X')) {
            cout << "перемога буде!" << endl;
            break;
        }
        if (c1.CheckWin('O')) {
            cout << "робот переміг" << endl;
            break;
        }
        if (d1.IsDraw()) {
            cout << "нічия" << endl;
            break;
        }
    }
    return 0;
}