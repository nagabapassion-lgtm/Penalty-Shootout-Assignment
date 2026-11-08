#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int team_A_score, team_B_score, round_no;

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
        while (round_no <= 5)
        {
            if (get_kick('A') == 'G')
            {
                team_A_score++;
            }
            if (get_kick('B') == 'G')
            {
                team_B_score++;
            }

            /* 3. Check whether the shootout can continue */
            if (is_decided())
            {
                break;
            }
            round_no++;
        }

        /* 4 and 5. Determine the outcome, then finish or restart */
        restart = announce_result();

    } while (restart == 1);

    return 0;
}

/* Ask a team for its kick until the answer is G or M */
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

/* Returns 1 if the trailing team can no longer catch up, otherwise 0 */
int is_decided(void)
{
    int Difference = abs(team_A_score - team_B_score);

    if (Difference > (5 - round_no))
    {
        printf("\n-----Early Win Detected-----\n\n");
        return 1;
    }
    return 0;
}

/* Prints the scores and the result. Returns 1 on a draw (restart), otherwise 0 */
int announce_result(void)
{
    printf("Team A Score: %d\n", team_A_score);
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