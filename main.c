#include <stdio.h>
#include "setDefault.c"
#include "game.c"

int main()
{
    char players[2];
    get_players(players);

    char ticTac[3][3];
    setDefault(ticTac);

    // display_board(ticTac);

    for (int i = 1; i < 10;)
    {
        display_board(ticTac);
        char position;
        enum boolean isEven = i % 2 == 0;
        const char currentPlayer = players[isEven];

        printf("Player %c turns: ", currentPlayer);
        scanf(" %c[^\n]", &position);

        const enum boolean isPositionNotAvailable = set_postion_value(ticTac, position, currentPlayer);

        if (isPositionNotAvailable)
            printf("Entered position %c is not available.\n", position);
        else
            i++;

        char winner = check_for_winner(ticTac);

        if (winner)
        {
            printf("%c is winner\n", winner);
            display_board(ticTac);

            enum boolean wantToPlay = ask_for_another_round();
            if (wantToPlay)
            {
                setDefault(ticTac);
                i = 1;
            }
            else
            {
                return 0;
            }
        }

        // game over
        if (i == 10)
        {
            printf("Draw\n");
            display_board(ticTac);

            enum boolean wantToPlay = ask_for_another_round();

            if (wantToPlay)
            {
                setDefault(ticTac);
                i = 1;
            }
            else
            {
                return 0;
            }
        }

        // printf("Position %c\n", position);
    }
}
