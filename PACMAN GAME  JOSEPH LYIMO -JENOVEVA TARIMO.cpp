#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

const int WIDTH = 20; // Width of the game grid
const int HEIGHT = 10; // Height of the game grid

int pacmanX, pacmanY; // Pacman's current position
int score; // Player's score

enum Direction { UP, DOWN, LEFT, RIGHT }; // Possible directions

char grid[HEIGHT][WIDTH] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '#', '#', '#', '.', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '.', '#'},
    {'#', '.', '#', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
    {'#', '.', '#', '.', '#', '#', '.', '#', '.', '#', '#', '#', '#', '#', '#', '.', '#', '.', '#'},
    {'#', '.', '#', '.', '#', '#', '.', '#', '.', '#', '#', '#', '#', '#', '#', '.', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

void drawGrid() {
    system("cls"); // Clear the console

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

void movePacman(Direction dir) {
    int newX = pacmanX;
    int newY = pacmanY;

    if (dir == UP) {
        newX--;
    } else if (dir == DOWN) {
        newX++;
    } else if (dir == LEFT) {
        newY--;
    } else if (dir == RIGHT) {
        newY++;
    }

    if (grid[newX][newY] != '#') {
        if (grid[newX][newY] == '.') {
            score++;
        }

        grid[pacmanX][pacmanY] = ' ';
        pacmanX = newX;
        pacmanY = newY;
        grid[pacmanX][pacmanY] = 'C';

        drawGrid();
        cout << "Score: " << score << endl;
    }
}

int main() {
    pacmanX = 1;
    pacmanY = 1;
    score = 0;

    grid[pacmanX][pacmanY] = 'C';

    drawGrid();
    cout << "Score: " << score << endl;
    cout << "Use arrow keys to move. Press 'Q' to quit." << endl;

    while (true) {
        if (_kbhit()) {
            char key = _getch();

            if (key == 'q' || key == 'Q') {
                break;
            } else if (key == 72) { // Up arrow key
                movePacman(UP);
            } else if (key == 80) { // Down arrow key
                movePacman(DOWN);
            } else if (key == 75) { // Left arrow key
                movePacman(LEFT);
            } else if (key == 77) { // Right arrow key
                movePacman(RIGHT);
            }
        }
    }

    return 0;
}