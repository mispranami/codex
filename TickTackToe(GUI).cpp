#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

// Function to check if a player has won
bool checkWin(char board[3][3], char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

// Function to check if the board is full (draw)
bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false; // Empty cell found
            }
        }
    }
    return true; // Board is full
}

int main() {
    const int windowSize = 300;
    const int cellSize = windowSize / 3;

    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char currentPlayer = 'X';

    sf::RenderWindow window(sf::VideoMode(windowSize, windowSize), "Tic Tac Toe");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                int x = event.mouseButton.x / cellSize;
                int y = event.mouseButton.y / cellSize;

                if (board[y][x] == ' ' && !checkWin(board, 'X') && !checkWin(board, 'O') && !checkDraw(board)) {
                    board[y][x] = currentPlayer;

                    if (checkWin(board, currentPlayer)) {
                        cout << "Player " << currentPlayer << " wins!" << endl;
                    } else if (checkDraw(board)) {
                        cout << "The game is a draw!" << endl;
                    }

                    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                }
            }
        }

        window.clear();

        // Draw the Tic Tac Toe grid
        for (int i = 1; i < 3; ++i) {
            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(i * cellSize, 0)),
                sf::Vertex(sf::Vector2f(i * cellSize, windowSize))
            };

            window.draw(line, 2, sf::Lines);

            line[0] = sf::Vertex(sf::Vector2f(0, i * cellSize));
            line[1] = sf::Vertex(sf::Vector2f(windowSize, i * cellSize));

            window.draw(line, 2, sf::Lines);
        }

        // Draw X and O on the board
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == 'X') {
                    sf::RectangleShape line(sf::Vector2f(cellSize - 20, 10));
                    line.setPosition(j * cellSize + 10, i * cellSize + 10);
                    line.rotate(45);
                    window.draw(line);

                    line.setRotation(-45);
                    line.setPosition(j * cellSize + 10, (i + 1) * cellSize - 10);
                    window.draw(line);
                } else if (board[i][j] == 'O') {
                    sf::CircleShape circle(cellSize / 2 - 10);
                    circle.setPosition(j * cellSize + 10, i * cellSize + 10);
                    window.draw(circle);
                }
            }
        }

        window.display();
    }

    return 0;
}
