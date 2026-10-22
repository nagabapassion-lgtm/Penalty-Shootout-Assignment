#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>

int main()
{
    char Aresult, Bresult;
    uint8_t team_A_score, team_B_score, round, Difference;
    uint8_t a = 0;                          
    int8_t Diff;
    int c;

    do {                                    // outer loop as long as a = 0
        team_A_score = 0;
        team_B_score = 0;
        round = 1;

        while (round < 6)
        {
            // Team A's kick
            do {
                printf("Record Team A's result in the round %d as a Goal(G) or a miss(M):\n", round);
                scanf(" %c", &Aresult);
                while ((c = getchar()) != '\n' && c != EOF);

                Aresult = toupper(Aresult);
                if (Aresult != 'G' && Aresult != 'M')
                {
                     printf("Error: you have entered an unacceptable value!\nPlease Try Again\n");
                }
            } while (Aresult != 'G' && Aresult != 'M');

            if (Aresult == 'G')
            {
                ++team_A_score;
            }

            // Team B's kick
            do {
                printf("Record Team B's result in the round %d as a Goal(G) or a miss(M):\n", round);
                scanf(" %c", &Bresult);
                while ((c = getchar()) != '\n' && c != EOF);

                Bresult = toupper(Bresult);
                if (Bresult != 'G' && Bresult != 'M')
                {
                     printf("Error: you have entered an unacceptable value!\nPlease Try Again\n");
                }
            } while (Bresult != 'G' && Bresult != 'M');

            if (Bresult == 'G')
            {
                ++team_B_score;
            }

            // team can no longer catch up
            Diff = team_A_score - team_B_score;
            Difference = abs(Diff);

            if (Difference > (5 - round))
            {
                break;
            }
            ++round;
        }

        printf("Team A Score: %d\n", team_A_score);
        printf("Team B Score: %d\n", team_B_score);

        // Determining the winner
        if (team_A_score > team_B_score)
        {
            printf("TEAM A WINS!\n");
            a = 1;
        }
        else if (team_B_score > team_A_score)
        {
            printf("TEAM B WINS!\n");
            a = 1;
        }
        else
        {
            printf("SHOOTOUT IS A DRAW (another 5 kicks each)\n");
        }

    } while (a == 0);

    return 0;
}