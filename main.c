/**
 * @name Connect 4 Masters Game
 * @version 1.0
 * @author Albert Hadacek (40446686)
 * 
 * MAIN FEATURES OF THE GAME
 * 
 * - Local Multiplayer of 2 players
 * - Custom Board Size (7-14)
 * 
 * 
 */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct gameOptions
{
    int rows;
    int columns;
};

struct move
{
    int x;
    int y;
};

struct game
{
    int currentPlayer;
    int **board;
};

// Function declarations
int verifyAndSetIntInput(char message[], int min, int max);
void configureGame(struct gameOptions *go);
void displaySetup(struct gameOptions go);
void prepareBoard(struct gameOptions go, struct game *g);
void printBoard(struct gameOptions go, struct game g);
void makeMove(struct gameOptions go, struct game *g, struct move *m);
bool determineWinner(struct gameOptions go, struct game g, struct move m);
void clear_stream(FILE *in);

int main(void)
{

    struct gameOptions go;
    struct game g;
    struct move m;

    // Setting up the configuration of the game
    configureGame(&go);
    // Displaying the configuration
    displaySetup(go);
    // Preparing the initial board based on the size provided by the user
    prepareBoard(go, &g);
    // Setting up the flag for the game
    bool isOn = true;
    while (isOn)
    {
        // Printing the board before every move
        printBoard(go, g);
        // Prompt the player to make a move
        makeMove(go, &g, &m);
        // check if someone has won
        if (determineWinner(go, g, m))
        {
            printf("Player %d has won! \n \n", g.currentPlayer);
            printBoard(go, g);
            isOn = false;
        }
        // Change player
        g.currentPlayer = g.currentPlayer == 1 ? 2 : 1;
    }

    return 0;
}

void configureGame(struct gameOptions *go)
{
    printf(" \n \n *** WELCOME TO THE CONNECT 4 MASTERS GAME *** \n \n");
    go->rows = verifyAndSetIntInput("Define the number of rows and columns", 7, 14);
    go->columns = go->rows;
}

void displaySetup(struct gameOptions go)
{
    printf("============== \n");
    printf("Size of your board will be %d x %d \n", go.rows, go.columns);
    printf("============== \n \n");
}

void printBoard(struct gameOptions go, struct game g)
{
    for (int i = 0; i < go.rows; i++)
    {
        for (int j = 0; j < go.columns; j++)
        {
            printf("%d ", g.board[i][j]);
        }
        printf("\n");
    }
    printf("\n \n");
}

void prepareBoard(struct gameOptions go, struct game *g)
{
    g->board = (int **)malloc(go.rows * sizeof(int *));
    g->currentPlayer = 1;
    for (int i = 0; i < go.rows; i++)
    {
        g->board[i] = (int *)malloc(go.columns * sizeof(int));
    }

    for (int i = 0; i < go.rows; i++)
    {
        for (int j = 0; j < go.columns; j++)
        {
            g->board[i][j] = 0;
        }
    }
}

void makeMove(struct gameOptions go, struct game *g, struct move *m)
{
    m->x = 0;
    m->y = 0;
    printf("Player's %d move. \n \n", g->currentPlayer);
    bool isFree = true;

    while (isFree)
    {
        m->x = verifyAndSetIntInput("Pick X coordinate", 1, go.rows) - 1;
        m->y = verifyAndSetIntInput("Pick Y coordinate", 1, go.columns) - 1;
        printf(" \n \n");

        if (g->board[m->x][m->y] == 0)
        {
            isFree = false;
            g->board[m->x][m->y] = g->currentPlayer;
        }
        else
        {
            printf("That space is already taken! \n \n");
        }
    }
}

// https://www.daniweb.com/programming/software-development/threads/386198/only-accept-integer-input-with-scanf
void clear_stream(FILE *in)
{
    int ch;

    clearerr(in);

    do
    {
        ch = getc(in);
    } while (ch != '\n' && ch != EOF);

    clearerr(in);
}

int verifyAndSetIntInput(char message[], int min, int max)
{
    int input = 0;

    printf("%s (%d - %d) \n", message, min, max);

    // https://www.daniweb.com/programming/software-development/threads/386198/only-accept-integer-input-with-scanf
    fflush(stdout);
    while (scanf("%d", &input) != 1 || max < input || input < min)
    {
        clear_stream(stdin);
        printf("Invalid value. Please try again. \n ");
        printf("%s (%d - %d) \n", message, min, max);
        fflush(stdout);
    }

    return input;
}

bool determineWinner(struct gameOptions go, struct game g, struct move m)
{
    // Checking rows
    int count = 0;
    for (int i = 0; i < go.columns; i++)
    {
        if (g.board[m.x][i] == g.currentPlayer)
        {
            count++;
        }
        else
        {
            count = 0;
        }

        if (count >= 4)
        {
            return true;
        }
    }
    // Checking columns
    count = 0;
    for (int i = 0; i < go.rows; i++)
    {
        if (g.board[i][m.y] == g.currentPlayer)
        {
            count++;
        }
        else
        {
            count = 0;
        }

        if (count >= 4)
        {
            return true;
        }
    }
    // Checking diagonals L -> R
    for (int i = 3; i < go.rows; i++)
    {
        for (int j = 3; j < go.columns - 3; j++)
        {
            if (g.board[i][j] == g.currentPlayer && g.board[i - 1][j + 1] == g.currentPlayer && g.board[i - 2][j + 2] == g.currentPlayer && g.board[i - 3][j + 3] == g.currentPlayer)
            {
                return true;
            }
        }
    }

    //Checking diagonals R -> L
    for (int i = 3; i < go.rows; i++)
    {
        for (int j = 3; j < go.columns; j++)
        {
            if (g.board[i][j] == g.currentPlayer && g.board[i - 1][j - 1] == g.currentPlayer && g.board[i - 2][j - 2] == g.currentPlayer && g.board[i - 3][j - 3] == g.currentPlayer)
            {
                return true;
            }
        }
    }
    return false;
}
