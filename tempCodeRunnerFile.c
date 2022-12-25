if (isValidPlayer(players[i]) && !isBothPlayerSame)
            i++;
        else if (isBothPlayerSame)
            printf("Player 1 and Player 2 must be different.\nPlayer 1 is %c and Player 2 %c.\n", players[0], players[1]);
        else
            printf("Invalid input.\n");