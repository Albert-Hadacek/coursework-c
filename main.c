/**
 * @name Connect 4 Masters Game
 * @version 1.0
 * @author Albert Hadacek (40446686)
 * 
 * MAIN FEATURES OF THE GAME
 * 
 * - Local Multiplayer of 2 players
 * - Custom Board Size (4-10)
 * - Singleplayer vs. optimized AI using the Minimax Algorithm
 * - Option to rewind in the game 
 * - Option to record a game into a text file
 * - Option to go through the saved gameplays
 * 
 *  Enjoy!!!
 */

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

struct gameOptions
{
    char mode;
    char recordGame;
    int rows;
    int columns;
};

struct move
{
    int x;
    int y;
    int player;
};

struct game
{
    int currentPlayer;
    // movesHistory
    // board
};

// Function declarations
char verifyAndSetStrInput(char conditions[], char message[]);
int verifyAndSetIntInput(char message[]);
void configureGame(struct gameOptions *go);
void displaySetup(struct gameOptions go);
char determineAction();
char *generateFileName(size_t length);

int main(void)
{

    struct gameOptions go;
    struct game g;

    printf("%s", generateFileName(5));

    // Determining if the player wants to play or review a previous game
    char a = determineAction();

    if (a == 'P')
    {
        // Setting up the configuration of the game
        configureGame(&go);
        // Displaying the configuration
        displaySetup(go);

        // Setting up the flag for the game
        int isOn = 1;
        while (isOn)
        {
            // Singleplayer Mode
            if (go.mode == 'S')
            {
            }

            // Multiplayer Mode
            if (go.mode == 'M')
            {
            }
        }

        // Determining the winner
    }

    if (a == 'R')
    {
        // Getting content from a file specified by user

        // Displaying the replay of the specified game
    }

    return 0;
}

char determineAction()
{
    printf(" \n \n *** WELCOME TO THE CONNECT 4 MASTERS GAME *** \n \n");
    return verifyAndSetStrInput((char[]){'P', 'R'}, "Press P to play or press R to review one of your previous games");
}

void configureGame(struct gameOptions *go)
{
    go->mode = verifyAndSetStrInput((char[]){'M', 'S'}, "Press M for local multiplayer game or S for singleplayer game against our daunting AI");
    go->recordGame = verifyAndSetStrInput((char[]){'Y', 'N'}, "Press Y if you want to record the game, otherwise press N");
    go->columns = verifyAndSetIntInput("Define the number of columns (4 - 10)");
    go->rows = verifyAndSetIntInput("Define the number of rows (1-10)");
}

void displaySetup(struct gameOptions go)
{
    printf("============== \n");
    printf("This is your game configuration \n");
    printf("Game mode: %s \n", go.mode == "M" ? "Multiplayer" : "Singleplayer");
    printf("Your game %s \n", go.recordGame == "Y" ? " will be recorded" : " will not be recorded");
    printf("Size of your board will be %d x %d \n", go.rows, go.columns);
    printf("============== \n");
}

char verifyAndSetStrInput(char conditions[], char message[])
{
    char input;
    while ((input != conditions[0]) && (input != conditions[1]))
    {
        printf("%s \n", message);
        scanf(" %c", &input);
        while (getchar() != '\n')
        {
        };
    }

    return input;
}

int verifyAndSetIntInput(char message[])
{
    int input = 0;
    while (input > 10 || input < 4)
    {

        printf("%s \n", message);
        scanf(" %d", &input);
    }

    return input;
}

char *generateFileName(size_t length)
{
    const char charOptions[] = "abcdefghijklmnopqrstuvwxyz123456789";
    char *randomString;
    randomString = malloc(length + 1);

    for (int i = 0; i < length; i++)
    {
        int idx = rand() % (int)(sizeof(charOptions) - 1);
        randomString[i] = charOptions[idx];
    }

    randomString[length] = '\0';

    return randomString;
}