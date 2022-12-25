#include <stdio.h>
#include "setDefault.c"
#include "game.c"

void main()
{
    char players[2];
    get_players(players);

    char ticTac[3][3];
    setDefault(ticTac);

    display_board(ticTac);
}