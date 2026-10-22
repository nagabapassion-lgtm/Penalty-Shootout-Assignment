#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
    uint8_t team_A_score = 3;
    uint8_t team_B_score = 2;
    uint8_t round = 5;
    uint8_t a = 1;
    int8_t Diff = -1;
    uint8_t Difference = 1;
    char Aresult = 'G';
    char Bresult = 'M';


    printf("team_A_score: Value = %u, Size = %zu byte\n", team_A_score, sizeof(team_A_score));
    printf("team_B_score: Value = %u, Size = %zu byte\n", team_B_score, sizeof(team_B_score));
    printf("round:        Value = %u, Size = %zu byte\n", round, sizeof(round));
    printf("a (flag):     Value = %u, Size = %zu byte\n", a, sizeof(a));
    printf("Diff:         Value = %d, Size = %zu byte\n", Diff, sizeof(Diff));
    printf("Difference:   Value = %u, Size = %zu byte\n", Difference, sizeof(Difference));
    printf("Aresult:      Value = %c, Size = %zu byte\n", Aresult, sizeof(Aresult));
    printf("Bresult:      Value = %c, Size = %zu byte\n", Bresult, sizeof(Bresult));


    printf("Address of team_A_score: %p\n", (void*)&team_A_score);
    printf("Address of Diff:         %p\n", (void*)&Diff);
    printf("Address of Difference:   %p\n", (void*)&Difference);

    

    return 0;
}