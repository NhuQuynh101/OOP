#include <iostream>
#include <vector>
using namespace std;

class GameOfLife {
    int m, n;
    vector<vector<int>> cur_state, next_state;

public:
    GameOfLife(int m, int n, vector<vector<int>> state) {
        this->m = m;
        this->n = n;
        cur_state = state;
        next_state = state;
    }

    int get_live_neighbors(int i, int j) {
        int c = 0;
        for (int a = i - 1; a <= i + 1; a++) {
            for (int b = j - 1; b <= j + 1; b++) {
                if (a >= 0 && a < m && b >= 0 && b < n && !(a == i && b == j) && cur_state[a][b] == 1) {
                    c++;
                }
            }
        }
        return c;
    }

    void play(int k) {
        while (k--) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    int live_neighbors = get_live_neighbors(i, j);
                    if (cur_state[i][j] == 1) {
                        if (live_neighbors < 2 || live_neighbors > 3) {
                            next_state[i][j] = 0;
                        }
                    } else {
                        if (live_neighbors == 3) {
                            next_state[i][j] = 1;
                        }
                    }
                }
            }
            cur_state = next_state;
        }
    }

    void print() {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << cur_state[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int m, n, k;
    cin >> m >> n;

    vector<vector<int>> state(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> state[i][j];
        }
    }

    cin >> k;

    GameOfLife game(m, n, state);
    game.play(k);
    game.print();

    return 0;
}