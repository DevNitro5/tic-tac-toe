#include <stdio.h>
#include "setDefault.c"
#include "game.c"

int main()
{
    char players[2];
    get_players(players);

    char ticTac[3][3];
    setDefault(ticTac);

    for (int i = 1; i < 10;)
    {
        display_board(ticTac);

        char position;

        const int index = i % 2 == 0;
        const char currentPlayer = players[index];

        printf("Player %c turns: ", currentPlayer);
        scanf(" %c[^\n]", &position);

        const boolean isPositionAvailable = set_postion_value(ticTac, position, currentPlayer);
        if (isPositionAvailable)
            i++;
        else
        {
            printf("Entered position %c is not available.\n", position);
            continue;
        }

        const char winner = get_winner(ticTac);
        const boolean isGameOver = i == 10;
        if (winner || isGameOver)
        {
            winner ? printf("%c is winner\n", winner) : printf("Draw\n");
            display_board(ticTac);

            const boolean wantToPlay = ask_for_another_round();
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

    }
}
