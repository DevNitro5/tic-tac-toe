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

        if (isBothPlayerSame)
            printf("Player 1 and Player 2 must be different.\nPlayer 1 is %c and Player 2 %c.\n", players[0], players[1]);
        else if (isValidPlayer(players[i]))
            i++;
        else
            printf("Invalid input.\n");
    }
}

enum boolean set_postion_value(char arr[3][3], char position, char value)
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            const char currentVal = arr[i][j];

            if (currentVal == position)
            {
                arr[i][j] = value;
                return false;
            }
        }
    }

    return true;
}

// char check_for_winner(char ticTac[3][3])
// {

//     if (ticTac[0][0] == ticTac[0][1] && ticTac[0][1] == ticTac[0][2])
//         return ticTac[0][1];

//     if (ticTac[1][0] == ticTac[1][1] && ticTac[1][1] == ticTac[1][2])
//         return ticTac[1][0];

//     if (ticTac[2][0] == ticTac[2][1] && ticTac[2][1] == ticTac[2][2])
//         return ticTac[1][0];

//     if (ticTac[0][0] == ticTac[1][0] && ticTac[1][0] == ticTac[2][0])
//         return ticTac[1][0];

//     if (ticTac[0][1] == ticTac[1][1] && ticTac[1][1] == ticTac[2][1])
//         return ticTac[1][1];

//     if (ticTac[0][2] == ticTac[1][2] && ticTac[1][2] == ticTac[2][2])
//         return ticTac[1][2];

//     if (ticTac[0][0] == ticTac[1][1] && ticTac[1][1] == ticTac[2][2])
//         return ticTac[1][1];

//     if (ticTac[0][2] == ticTac[1][1] && ticTac[1][1] == ticTac[2][0])
//         return ticTac[1][1];

//     return '\0';

//     // 00 01 02
//     // 10 11 12
//     // 20 21 22
// }

char check_for_winner(char ticTac[3][3])
{

    int count;

    // row checking
    for (int i = 0; i < 3; i++)
    {
        count = 0;
        for (int j = 0; j < 2; j++)
        {
            const char nextVal = ticTac[i][j + 1];
            const char currentVal = ticTac[i][j];

            if (currentVal == nextVal)
                count++;
        }

        if (count == 2)
            return ticTac[i][0];
    }

    // column checking
    for (int i = 0; i < 3; i++)
    {
        count = 0;
        for (int j = 0; j < 2; j++)
        {
            const char nextVal = ticTac[j + 1][i];
            const char currentVal = ticTac[j][i];
            // printf("next[%d][%d]: %c and curr[%d][%d]: %c\n", j + 1, i, nextVal, j, i, currentVal);

            if (currentVal == nextVal)
                count++;
        }

        if (count == 2)
            return ticTac[0][i];
    }

    const char middleVal = ticTac[1][1];
    if (ticTac[0][0] == middleVal && middleVal == ticTac[2][2])
        return middleVal;

    if (ticTac[0][2] == middleVal && middleVal == ticTac[2][0])
        return middleVal;

    return '\0';
}


enum boolean ask_for_another_round()
{
    char response;

    printf("Want to play another round? y/n :");
    scanf(" %c[\n]", &response);

    if (response == 'y' || response == 'Y')
        return true;

    return false;
}
