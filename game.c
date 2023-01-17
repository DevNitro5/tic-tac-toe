#include <stdio.h>
#include <ctype.h>

enum Boolean
{
    false,
    true
};
typedef enum Boolean boolean;

boolean isValidPlayer(char player)
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

        const boolean isBothPlayerSame = tolower(players[0]) == tolower(players[1]);

        if (isBothPlayerSame)
            printf("Player 1 and Player 2 must be different.\nPlayer 1 is %c and Player 2 is %c.\n", players[0], players[1]);
        else if (isValidPlayer(players[i]))
            i++;
        else
            printf("Invalid input.\n");
    }
}

boolean set_postion_value(char arr[3][3], char position, char value)
{

    // if position value is not between char 1-9
    if (!(position > 48 && position < 58))
        return false;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            const char currentVal = arr[i][j];

            if (currentVal == position)
            {
                arr[i][j] = value;
                return true;
            }
        }
    }

    return false;
}

    // 00 01 02
    // 10 11 12
    // 20 21 22
char get_winner(char ticTac[3][3])
{
    int  rowMatchCount,columnMatchCount;
    
    for (int i = 0; i < 3; i++)
    {
       rowMatchCount = 0;
       columnMatchCount = 0;
        for (int j = 0; j < 2; j++)
        {
            const char nextRowVal = ticTac[i][j + 1];
            const char currentRowVal = ticTac[i][j];

            if (currentRowVal == nextRowVal)
                rowMatchCount++;

            const char nextColumnVal = ticTac[j + 1][i];
            const char currentColumnVal = ticTac[j][i];
            // printf("next[%d][%d]: %c and curr[%d][%d]: %c\n", j + 1, i, nextVal, j, i, currentVal);

            if (currentColumnVal == nextColumnVal)
                columnMatchCount++;
        }

        if (rowMatchCount == 2)
            return ticTac[i][0];

        if (columnMatchCount == 2)
            return ticTac[0][i];
    }

    const char middleVal = ticTac[1][1];
    if (ticTac[0][0] == middleVal && middleVal == ticTac[2][2])
        return middleVal;

    if (ticTac[0][2] == middleVal && middleVal == ticTac[2][0])
        return middleVal;

    return '\0';
}

boolean ask_for_another_round()
{
    char response;

    printf("Want to play another round? y/n: ");
    scanf(" %c[^\n]", &response);

    return (response == 'y' || response == 'Y');
}
