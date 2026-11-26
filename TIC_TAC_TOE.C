#include <stdio.h>

/* Function Declarations */
void initBoard(char board[3][3]);
void displayBoard(char board[3][3]);
void displayScoreboard(char p1[], char p2[], int scoreX, int scoreO, int draws);
int makeMove(char board[3][3], char mark, char playerName[]);
int checkWin(char board[3][3], char mark);
int checkDraw(char board[3][3]);

int main(void) {
    char board[3][3];
    char player1[30], player2[30];
    int scoreX = 0, scoreO = 0, draws = 0;
    int choice;
    char playAgain;

    printf("=== TWO-PLAYER TIC-TAC-TOE GAME ===\n");
    printf("Enter Player 1 First Name (X): ");
    scanf("%s", player1);
    printf("Enter Player 2 First Name (O): ");
    scanf("%s", player2);

    do {
        printf("\n--- MAIN MENU ---\n");
        printf("1. Play Game\n");
        printf("2. View Scoreboard\n");
        printf("3. Reset Scores\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            do {
                initBoard(board);
                char currentMark = 'X';
                int gameOver = 0;

                while (gameOver == 0) {
                    displayBoard(board);

                    int valid;
                    if (currentMark == 'X') {
                        valid = makeMove(board, 'X', player1);
                    } else {
                        valid = makeMove(board, 'O', player2);
                    }

                    if (valid == 1) {
                        if (checkWin(board, currentMark) == 1) {
                            displayBoard(board);
                            if (currentMark == 'X') {
                                printf("Congratulations %s (X)! You win!\n", player1);
                                scoreX++;
                            } else {
                                printf("Congratulations %s (O)! You win!\n", player2);
                                scoreO++;
                            }
                            gameOver = 1;
                        } else if (checkDraw(board) == 1) {
                            displayBoard(board);
                            printf("Match Draw! All cells are filled.\n");
                            draws++;
                            gameOver = 1;
                        } else {
                            if (currentMark == 'X') {
                                currentMark = 'O';
                            } else {
                                currentMark = 'X';
                            }
                        }
                    }
                }

                displayScoreboard(player1, player2, scoreX, scoreO, draws);

                printf("\nDo you want to play again? (y/n): ");
                scanf(" %c", &playAgain);

            } while (playAgain == 'y' || playAgain == 'Y');

        } else if (choice == 2) {
            displayScoreboard(player1, player2, scoreX, scoreO, draws);
        } else if (choice == 3) {
            scoreX = 0;
            scoreO = 0;
            draws = 0;
            printf("Scores reset to 0!\n");
        } else if (choice == 4) {
            printf("Final Scoreboard:\n");
            displayScoreboard(player1, player2, scoreX, scoreO, draws);
            printf("Thank you for playing!\n");
            break;
        } else {
            printf("Invalid choice! Please enter 1 to 4.\n");
        }

    } while (1);

    return 0;
}

/* Fill the 3x3 board with numbers '1' to '9' */
void initBoard(char board[3][3]) {
    char cell = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = cell;
            cell++;
        }
    }
}

/* Print the 3x3 board */
void displayBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf("  %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2) {
            printf(" ---|---|---\n");
        }
    }
    printf("\n");
}

/* Print current scores */
void displayScoreboard(char p1[], char p2[], int scoreX, int scoreO, int draws) {
    printf("\n--- SCOREBOARD ---\n");
    printf("%s (X) Wins : %d\n", p1, scoreX);
    printf("%s (O) Wins : %d\n", p2, scoreO);
    printf("Draws       : %d\n", draws);
    printf("------------------\n");
}

/* Ask player for a cell (1-9) and validate it */
int makeMove(char board[3][3], char mark, char playerName[]) {
    int pos;
    printf("%s (%c), enter cell (1-9): ", playerName, mark);
    scanf("%d", &pos);

    if (pos < 1 || pos > 9) {
        printf("Invalid number! Choose between 1 and 9.\n");
        return 0;
    }

    int row = (pos - 1) / 3;
    int col = (pos - 1) % 3;

    if (board[row][col] == 'X' || board[row][col] == 'O') {
        printf("Cell already taken! Try another.\n");
        return 0;
    }

    board[row][col] = mark;
    return 1;
}

/* Check rows, columns, and diagonals for a winner */
int checkWin(char board[3][3], char mark) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) {
            return 1;
        }
        if (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark) {
            return 1;
        }
    }
    if (board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) {
        return 1;
    }
    if (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark) {
        return 1;
    }
    return 0;
}

/* Check if all 9 cells are filled */
int checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return 0;
            }
        }
    }
    return 1;
}
