#include <stdio.h>

enum boolean
{
    false,
    true
};

enum boolean isValidPlayer(char player)
{
    switch (player)
    {
    case 'X':
    case 'O':
    case 'x':
    case 'o':
        return true;
    default:
        return false;
    }
}

void display_board(char game[3][3])
{
    printf("%c | %c | %c\n", game[0][0], game[0][1], game[0][2]);
    printf("----------\n");
    printf("%c | %c | %c\n", game[1][0], game[1][1], game[1][2]);
    printf("----------\n");
    printf("%c | %c | %c\n", game[2][0], game[2][1], game[2][2]);
}

void get_players(char players[2])
{
    for (int i = 0; i < 2;)
    {
        printf("Player %d: ", i + 1);
        scanf(" %c[^\n]", &players[i]);

        enum boolean isBothPlayerSame = players[0] == players[1];

        if (isValidPlayer(players[i]) && !isBothPlayerSame)
            i++;
        else if (isBothPlayerSame)
            printf("Player 1 and Player 2 must be different.\nPlayer 1 is %c and Player 2 %c.\n", players[0], players[1]);
        else
            printf("Invalid input.\n");
    }
}