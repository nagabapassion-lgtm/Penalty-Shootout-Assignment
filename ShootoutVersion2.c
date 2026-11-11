
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define KICKS_PER_ROUND 5    /*kicks each team takes per shootout */

int team_A_score, team_B_score, round_no;
char team_A_kicks[KICKS_PER_ROUND];   /*Team A's kicks ('G' or 'M') */
char team_B_kicks[KICKS_PER_ROUND];   /*Team B's kicks ('G' or 'M') */

char get_kick(char team);
int  is_decided(void);
int  announce_result(void);

int main(void)
{
    int restart;

    do {
        /* 1. Prepare the shootout */
        team_A_score = 0;
        team_B_score = 0;
        round_no = 1;

        /* 2. Conduct each round (stops early when the result is decided) */
        while (round_no <= KICKS_PER_ROUND)
        {
            /*2.1 read & validate Team A's kick, store it, update score */
            if (get_kick('A') == 'G')
            {
                team_A_kicks[round_no - 1] = 'G';
                team_A_score++;
            }
            else
            {
                team_A_kicks[round_no - 1] = 'M';
            }

            /*2.2 read & validate Team B's kick, store it, update score */
            if (get_kick('B') == 'G')
            {
                team_B_kicks[round_no - 1] = 'G';
                team_B_score++;
            }
            else
            {
                team_B_kicks[round_no - 1] = 'M';
            }

            /* 3. Check whether the shootout can continue */
            if (is_decided())
            {
                printf("\n-----Early Win Detected-----\n\n");
                break;
            }
            round_no++;
        }

        /* 4 and 5. Determine the outcome, then finish or restart */
        restart = announce_result();

    } while (restart == 1);

    return 0;
}

/* Ask a user for the team's kick result  until the answer is G or M */
char get_kick(char team)
{
    char kick;
    int c;

    do {
        printf("Record Team %c's result in the round %d as a Goal(G) or a miss(M):\n", team, round_no);
        scanf(" %c", &kick);
        while ((c = getchar()) != '\n' && c != EOF);

        kick = toupper(kick);
        if (kick != 'G' && kick != 'M')
        {
            printf("Error: you have entered an unacceptable value!\nPlease Try Again\n");
        }
    } while (kick != 'G' && kick != 'M');

    return kick;
}

/* Returns 1 if the trailing team can no longer catch up, otherwise 0.*/
int is_decided(void)
{
    int Difference = abs(team_A_score - team_B_score);

    return Difference > (KICKS_PER_ROUND - round_no);
}

/* Prints the kick trace, the scores, and the result. Returns 1 on a draw (restart), otherwise 0. */
int announce_result(void)
{
    int i;
    int rounds_played = (round_no > KICKS_PER_ROUND) ? KICKS_PER_ROUND : round_no;

    /* Print every kick that was actually taken this shootout */
    printf("\n--- Kick results per round ---\n");
    for (i = 0; i < rounds_played; i++)
    {
        printf("Round %d:  Team A = %c   Team B = %c\n", i + 1, team_A_kicks[i], team_B_kicks[i]);
    }

    printf("\nTeam A Score: %d\n", team_A_score);
    printf("Team B Score: %d\n", team_B_score);

    if (team_A_score > team_B_score)
    {
        printf("TEAM A WINS!\n");
        return 0;
    }
    else if (team_B_score > team_A_score)
    {
        printf("TEAM B WINS!\n");
        return 0;
    }
    else
    {
        printf("SHOOTOUT IS A DRAW (another 5 kicks each)\n");
        return 1;
    }
}